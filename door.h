#ifndef DOOR_H
#define DOOR_H

#include "doorcond.h"
#include "elevctrlinterplay.h"

class Door : public ElevCtrlInterplay
{
private:
	DoorCond m_condition;
public:
	void openDoor();
	void closeDoor();
	DoorCond getCondition();
};

#endif