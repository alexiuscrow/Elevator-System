#include "stdafx.h"
#include <iostream>
#include "building.h"
#include "firstlastfloor.h"
#include "callbtn.h"
#include "interjacentfloor.h"


Building::Building(std::string nameOfBuilding, unsigned int countOfFloors) : m_nameOfBuilding(nameOfBuilding), m_countOfFloors(countOfFloors){
	m_elevator = new Elevator(countOfFloors);

	for (unsigned int i = 0; i < countOfFloors; i++)
	{
		if (i == 0)
		{
			m_floors.push_back(new FirstLastFloor(new CallBtn(UP, m_elevator, i+1)));
			
		}
		else if (i == countOfFloors - 1)
		{
			m_floors.push_back(new FirstLastFloor(new CallBtn(DOWN, m_elevator, i + 1)));
		}
		else
		{
			m_floors.push_back(new InterjacentFloor(new CallBtn(UP, m_elevator, i + 1),
				new CallBtn(DOWN, m_elevator, i + 1)));
		}
	}

}

Building::~Building()
{
	for (unsigned int i = 0; i < m_floors.size(); i++)
		delete m_floors[i];

	delete m_elevator;
}

Floor*& Building::getFloor(int numOfFloor)
{
	return m_floors[numOfFloor-1];
}

int Building::getCountOfFloors()
{
	return m_countOfFloors;
}

std::string Building::getNameOfBuilding()
{
	return m_nameOfBuilding;
}