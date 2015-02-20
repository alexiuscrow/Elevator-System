#ifndef ENGINE_H
#define ENGINE_H

#include "conddir.h"
#include <thread>

class Engine
{
private:
	const int SPEED = 3;
public:
	void moveNFloorsUp(int countOfFloors, int &currentFllor);
	void moveNFloorsDown(int countOfFloors, int &currentFllor);
	void stop(std::thread &thread);
};

#endif
