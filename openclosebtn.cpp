#include "stdafx.h"
#include <iostream>
#include "openclosebtn.h"
#include "elevator.h"

OpenCloseBtn::OpenCloseBtn(DoorCond condition, Elevator *elevator)
	: m_elevator(elevator)
{
	/*NOP*/
}

OpenCloseBtn::~OpenCloseBtn()
{
	delete m_elevator;
}

void OpenCloseBtn::push()
{
	std::cout << "Нажата кнопка \"Открыть двери\"" << std::endl;
	m_elevator->openDoor();
}