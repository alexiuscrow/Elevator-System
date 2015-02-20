#ifndef OPENCLOSEBTN_H
#define OPENCLOSEBTN_H

#include "button.h"
#include "doorcond.h"
#include "elevator.h"


class OpenCloseBtn: public Button
{
private: 
	DoorCond m_condition;
	Elevator* m_elevator;
public:
	OpenCloseBtn(DoorCond condition, Elevator *elevator);
	~OpenCloseBtn();
	void push();
};

#endif