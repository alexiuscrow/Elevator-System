#ifndef BUTTON_H
#define BUTTON_H

#include "conddir.h"

class Button
{
public:
	virtual void push();
	virtual void push(int numOfFloor);
};

#endif