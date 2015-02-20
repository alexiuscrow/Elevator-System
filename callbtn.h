#ifndef CALLBTN_H
#define CALLBTN_H

#include "button.h"
#include "conddir.h"
#include "elevator.h"

class CallBtn: public Button
{
private:
	DirectionCond m_direction;
	Elevator* m_elevator;
	unsigned int m_floor;

public:
	CallBtn(DirectionCond direction, Elevator *&elevator, int floor);
	~CallBtn();
	void push();
	DirectionCond getDirection();
};


#endif
