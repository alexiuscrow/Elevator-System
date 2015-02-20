#include "stdafx.h"
#include <iostream>
#include "stopbtn.h"

StopButton::StopButton(Elevator *elevator)
	: m_elevator(elevator)
{
	/*NOP*/
}

StopButton::~StopButton()
{
	delete m_elevator;
}

void StopButton::push()
{
	m_elevator->stop();
	std::cout << "Нажата кнопка \"Стоп\"" << std::endl;
}