#ifndef INTERJACENTFLOOR_H
#define INTERJACENTFLOOR_H

#include "floor.h"
#include "button.h"
#include <vector>

class InterjacentFloor : public Floor
{
private:
	std::vector<Button*> m_buttons;
public:
	InterjacentFloor(Button *btnUp, Button *btnDown);
	~InterjacentFloor();
	Button*& getButton(DirectionCond direction);
};

#endif