#include "stdafx.h"
#include "door.h"

void Door::openDoor()
{
	getMace().lock();
	getLogFile() << "����� �������" << std::endl;
	getMace().unlock();
}

void Door::closeDoor()
{
	getMace().lock();
	getLogFile() << "����� �������" << std::endl;
	getMace().unlock();
}