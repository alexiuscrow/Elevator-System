#ifndef DOOR_H
#define DOOR_H

#include "doorcond.h"

class Door
{
private:
	DoorCond m_condition;
public:
	void openDoor();
	void closeDoor();
	DoorCond getCondition();
};

#endif