#include "stdafx.h"
#include <iostream>
#include "floor.h"

int unsigned Floor::m_nextId;

Floor::Floor() : m_id(m_nextId++)
{
	/*NOP*/
}

int Floor::getId()
{
	return m_id;
}

