#include "stdafx.h"
#include "elevator.h"
#include "openclosebtn.h"
#include "stopbtn.h"
#include <chrono>
#include <thread>

Elevator::Elevator(int countOfFloors) : m_countOfFloors(countOfFloors), m_currFloor(1), m_destFloor(1)
{
	m_engine = new Engine();
	m_door = new Door();
	m_openCloseDoorBtn.push_back(new OpenCloseBtn(OPEN, this));
	m_openCloseDoorBtn.push_back(new OpenCloseBtn(CLOSE, this));
	m_stopBtn = new StopButton(this);
	m_condition = STOP;
	m_queueInside = new bool[countOfFloors];

	m_queueOutside = new bool*[countOfFloors];
	for (int i = 0; i < countOfFloors; i++)
		m_queueOutside[i] = new bool[2];
}

Elevator::~Elevator() 
{
	delete m_engine;
	delete m_door;
	delete m_openCloseDoorBtn[0];
	delete m_openCloseDoorBtn[1];
	delete m_stopBtn;
	delete m_queueInside;

	for (int i = 0; i < m_countOfFloors; i++)
		delete[] m_queueOutside[i];
}

std::vector<Button*>& Elevator::getCloseDoorBtn()
{
	return m_openCloseDoorBtn;
}

std::vector<Button*>& Elevator::getChoiceFloorBtn()
{
	return m_choiceFloorBtn;
}

Button*& Elevator::getStopBtn()
{
	return m_stopBtn;
}

void Elevator::changeDestFloor(int numOfFloor, DirectionCond condition)
{
	if (condition == m_condition)
	{
		if (condition == UP && numOfFloor > m_destFloor)
			m_destFloor = numOfFloor;
		else if (condition == DOWN && numOfFloor < m_destFloor)
			m_destFloor = numOfFloor;
	}
}

void Elevator::acceptDemandInside(int numOfFloor)
{
	getMace().lock();
	m_queueInside[numOfFloor - 1] = true;
	getLogFile() << "Вошедший пользователь указал " << numOfFloor << " этаж" << std::endl;
	changeDestFloor(numOfFloor, m_condition);
	getMace().unlock();

	if (m_destFloor != 0)
	{
		if (m_destFloor > m_currFloor && m_destFloor < numOfFloor)
			m_destFloor = numOfFloor;
		else if (m_currFloor > m_destFloor && numOfFloor < m_destFloor)
			m_destFloor = numOfFloor;
	}
}

void Elevator::acceptDemandOutside(int numOfFloor, DirectionCond condition)
{
	getMace().lock();
	m_queueOutside[numOfFloor - 1][condition] = true;
	getLogFile() << "Лифт был вызван на " << numOfFloor << " этаж" << std::endl;
	changeDestFloor(numOfFloor, condition);
	getMace().unlock();

	if (numOfFloor == m_destFloor)
	{
		m_destFloorNewCaller[0] = true;
		m_destFloorNewCaller[1] = (condition ? 0 : 1); // inversion
	}

	if (m_condition == STOP)
		move();
}

int Elevator::findNearFloor(){
	int nearestFloorUp = 0;
	int nearestFloorDown = 0;

	if (m_currFloor < m_countOfFloors)
	{
		for (int i = m_currFloor + 1; i < m_countOfFloors; i++)
		{
			if (m_queueOutside[i-1][UP] == true && m_queueOutside[i-1][DOWN] == true)
			{
				nearestFloorUp = i;
			}
		}
	}

	if (m_currFloor > 0)
	{
		for (int i = m_currFloor; i > 0; i--)
		{
			if (m_queueOutside[i-1][UP] == true && m_queueOutside[i-1][DOWN] == true)
			{
				nearestFloorDown = i;
			}
		}
	}
	
	if ((nearestFloorUp - m_currFloor) < (nearestFloorDown - m_currFloor * -1))
		return nearestFloorUp;
	else if (nearestFloorUp == 0 && nearestFloorDown == 0)
		return 0;
	else
		return nearestFloorDown;
}

void Elevator::move()
{
	if (m_condition == STOP)
	{
		m_destFloor = findNearFloor();

	MOVEONEFLOOR:
		// Установка направления, переместится на 1 этаж --------------------------------
		if (m_destFloor > m_currFloor)
		{
			m_condition = UP;
			m_engine->moveNFloorsUp(1, m_currFloor);
		}
		else
		{
			m_condition = DOWN;
			m_engine->moveNFloorsDown(1, m_currFloor);
		}
		//--------------------------------------------------------------------------------

		// Если приехали на этаж назначения ----------------------------------------------
		if (m_currFloor == m_destFloor)
		{
			// Затёрка заявок ------------------------------------------------------------
			if (m_queueOutside[m_currFloor - 1][m_condition])
			{
				m_queueOutside[m_currFloor - 1][m_condition] = false;

				if (m_queueInside[m_currFloor - 1])
					m_queueInside[m_currFloor - 1] = false;
			}
			else 
				m_queueInside[m_currFloor - 1] = false;
			//-----------------------------------------------------------------------------

			stop();
			m_door->openDoor();

			// Вызывал ли кто-то еще лифт с этого этажа пока мы ехали? --------------------
			if (m_destFloorNewCaller[0])
			{
				if (m_destFloorNewCaller[1])
					m_condition = UP;
				else
					m_condition = DOWN;

				m_destFloorNewCaller[1] = false;
				m_destFloorNewCaller[0] = false;

				m_door->closeDoor();

				//Зашедший в лифт выбирает этаж
				//Присвоение "m_queueInside" выбранный этаж

				goto MOVEONEFLOOR;
			}
			else
				m_door->closeDoor();
			//-----------------------------------------------------------------------------

			// Если лифт больше никтоне вызывал то обнуляем "этаж назначения" -------------
			int nearestFloor = findNearFloor();
			if (nearestFloor == 0)
			{
				m_destFloor = 0;   
				return;
			}
			//-----------------------------------------------------------------------------
		}
		//---------------------------------------------------------------------------------

		// Если на текущем этаже кто-то вызывал лифт в том направлении в котором мы движемся
		if (m_queueOutside[m_currFloor - 1][m_condition] || m_queueInside[m_currFloor - 1])
		{
			DirectionCond condBeforeTmpStop = m_condition;
			stop();
			m_door->openDoor();

			if (m_queueOutside[m_currFloor - 1][m_condition])
			{
				m_queueOutside[m_currFloor - 1][m_condition] = false;
				//Зашедший в лифт выбирает этаж
				//Присвоение "m_queueInside" выбранный этаж
			}
			else 
				m_queueInside[m_currFloor - 1] = false;

			m_door->closeDoor();
			m_condition = condBeforeTmpStop;
		}
		goto MOVEONEFLOOR;
		//---------------------------------------------------------------------------------
	}
}

void Elevator::stop()
{
	m_condition = STOP;
	m_engine->stop(); 
}

void Elevator::openDoor()
{
	m_door->openDoor();
	std::this_thread::sleep_for(std::chrono::seconds(M_LANDING_TIME));
	m_door->closeDoor();
}