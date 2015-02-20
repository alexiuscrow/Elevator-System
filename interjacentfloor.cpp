#include "stdafx.h"
#include "interjacentfloor.h"

InterjacentFloor::InterjacentFloor(Button *btnUp, Button *btnDown)
{
	m_buttons.push_back(btnUp);
	m_buttons.push_back(btnDown);
}

InterjacentFloor::~InterjacentFloor()
{
	for (unsigned int i = 0; i < m_buttons.size(); i++)
		delete m_buttons[i];
}

Button*&  InterjacentFloor::getButton(DirectionCond direction)
{
	return m_buttons[direction];
}