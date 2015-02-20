#include "stdafx.h"
#include <iostream>
#include "callbtn.h"

CallBtn::CallBtn(DirectionCond direction, Elevator *&elevator, int floor)
	: m_direction(direction), m_elevator(elevator), m_floor(floor)
{
	/*NOP*/
}

CallBtn::~CallBtn()
{
	delete m_elevator;
}

void CallBtn::push()
{
	std::cout << "Лифт вызван на " << m_floor << " этаж" << std::endl;
	m_elevator->acceptDemandOutside(m_floor, m_direction);
}

DirectionCond CallBtn::getDirection()
{
	return m_direction;
}