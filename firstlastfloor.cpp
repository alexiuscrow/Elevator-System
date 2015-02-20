#include "stdafx.h"
#include "firstlastfloor.h"

FirstLastFloor::FirstLastFloor(Button *btnUpOrDown) : m_button(btnUpOrDown)
{
	/*NOP*/
}

FirstLastFloor::~FirstLastFloor()
{
	delete m_button;
}

Button*&  FirstLastFloor::getButton()
{
	return m_button;
}