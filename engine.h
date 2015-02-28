#ifndef ENGINE_H
#define ENGINE_H

#include "conddir.h"
#include <thread>
#include "elevctrlinterplay.h"

class Engine : public ElevCtrlInterplay
{
private:
	const int SPEED = 3;
public:
	void moveNFloorsUp(int countOfFloors, int &currentFllor);
	void moveNFloorsDown(int countOfFloors, int &currentFllor);
	void stop();
};

#endif
