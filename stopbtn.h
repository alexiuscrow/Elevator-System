#ifndef STOPBUTTON_H
#define STOPBUTTON_H

#include "button.h"
#include "elevator.h"

class StopButton : public Button
{
private:
	Elevator* m_elevator;
public:
	StopButton(Elevator *elevator);
	~StopButton();
	void push();
};

#endif