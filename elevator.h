#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "door.h"
#include "engine.h"
#include "button.h"
//#include "callbtn.h"
//#include "choicefloorbtn.h"
//#include "openclosebtn.h"
//#include "stopbtn.h"
#include <vector>

class Elevator
{
	friend class CallBtn;
	friend class ChoiceFloorBtn;
	friend class StopButton;
	friend class OpenCloseBtn;

private:
	const int M_LANDING_TIME = 3;
	int m_countOfFloors;
	int m_currFloor;
	int m_destFloor;

	bool** m_queueOutside;
	bool* m_queueInside;
	bool m_destFloorNewCaller[2]; // [0] - вызванно/не вызванно, [1] - вверх/вниз
	DirectionCond m_condition;
	std::thread m_thdExecutMove;

	Engine* m_engine;
	Door* m_door;
	std::vector<Button*> m_openCloseDoorBtn;
	std::vector<Button*> m_choiceFloorBtn;
	Button* m_stopBtn;
	void changeDestFloor(int numOfFloor, DirectionCond condition);
	int findNearFloor();
	void stop();
	void openDoor();
protected:
	void acceptDemandInside(int numOfFloor);
	void acceptDemandOutside(int numOfFloor, DirectionCond condition);
	void move();
public:
	Elevator(int countOfFloors);
	~Elevator();

	std::vector<Button*>& getCloseDoorBtn();
	std::vector<Button*>& getChoiceFloorBtn();
	Button*& getStopBtn();
};

#endif