#include "stdafx.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "engine.h"

void Engine::moveNFloorsUp(int countOfFloors, int &currentFllor)
{
	while (currentFllor < countOfFloors)
	{
		std::this_thread::sleep_for(std::chrono::seconds(SPEED));
		currentFllor++;
		std::cout << currentFllor << " этаж: Лифт поднимается" << std::endl;
	}
	std::cout << currentFllor << " этаж: Лифт прибыл на место" << std::endl;
}

void Engine::moveNFloorsDown(int countOfFloors, int &currentFllor)
{
	while (currentFllor > countOfFloors)
	{
		std::this_thread::sleep_for(std::chrono::seconds(SPEED));
		currentFllor--;
		std::cout << currentFllor << " этаж: Лифт спускается" << std::endl;
	}
	std::cout << currentFllor << " этаж: Лифт прибыл на место" << std::endl;
}

void Engine::stop(std::thread &thread)
{
	if (thread.joinable())
	{
		thread.detach();
		std::cout << "Лифт был остановлен" << std::endl;
	}
}