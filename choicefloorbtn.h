#ifndef CHOICEFLOORBTN_H
#define CHOICEFLOORBTN_H

#include "button.h"
#include "elevator.h"

class ChoiceFloorBtn: public Button
{
private:
	Elevator* m_elevator;
	unsigned int m_id;
	static unsigned int m_nextId;
public:
	ChoiceFloorBtn(Elevator *&elevator);
	~ChoiceFloorBtn();
	void push(unsigned int numOfFloor);
};

#endif