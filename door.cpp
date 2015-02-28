#include "stdafx.h"
#include "door.h"

void Door::openDoor()
{
	getMace().lock();
	getLogFile() << "Дверь открыта" << std::endl;
	getMace().unlock();
}

void Door::closeDoor()
{
	getMace().lock();
	getLogFile() << "Дверь закрыта" << std::endl;
	getMace().unlock();
}