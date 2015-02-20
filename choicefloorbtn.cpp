#include "stdafx.h"
#include <iostream>
#include "choicefloorbtn.h"

int unsigned ChoiceFloorBtn::m_nextId;

ChoiceFloorBtn::ChoiceFloorBtn(Elevator *&elevator) 
	: m_elevator(elevator), m_id(m_nextId++)
{
	/*NOP*/
}

ChoiceFloorBtn::~ChoiceFloorBtn()
{
	delete m_elevator;
}

void ChoiceFloorBtn::push(unsigned int numOfFloor)
{
	std::cout << "������ ������ \"����� �� " << numOfFloor << " ����\"" << std::endl;
	m_elevator->acceptDemandInside(numOfFloor);
}