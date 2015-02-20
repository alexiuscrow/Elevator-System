#ifndef FIRSTLASTFLOOR_H
#define FIRSTLASTFLOOR_H

#include "floor.h"
#include "button.h"

class FirstLastFloor : public Floor
{
private:
	Button* m_button;
public:
	FirstLastFloor(Button *btn);
	~FirstLastFloor();
	Button*& getButton();
};

#endif