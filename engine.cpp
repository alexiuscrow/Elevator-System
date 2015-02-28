#include "stdafx.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "engine.h"

void Engine::moveNFloorsUp(int countOfFloors, int &currentFllor)
{
	while (currentFllor != (currentFllor + countOfFloors))
	{
		std::this_thread::sleep_for(std::chrono::seconds(SPEED));
		getMace().lock();
		getLogFile() << currentFllor << " ����: ���� �����������" << std::endl;
		currentFllor++;
		getMace().unlock();
	}
}

void Engine::moveNFloorsDown(int countOfFloors, int &currentFllor)
{
	while (currentFllor != (currentFllor - countOfFloors))
	{
		std::this_thread::sleep_for(std::chrono::seconds(SPEED));
		getMace().lock();
		getLogFile() << currentFllor << " ����: ���� ����������" << std::endl;
		currentFllor--;
		getMace().unlock();
	}
}

void Engine::stop()
{
	getMace().lock();
	getLogFile() << "���� ��� ����������" << std::endl;
	getMace().unlock();
}