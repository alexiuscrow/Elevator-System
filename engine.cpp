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
		std::cout << currentFllor << " ����: ���� �����������" << std::endl;
	}
	std::cout << currentFllor << " ����: ���� ������ �� �����" << std::endl;
}

void Engine::moveNFloorsDown(int countOfFloors, int &currentFllor)
{
	while (currentFllor > countOfFloors)
	{
		std::this_thread::sleep_for(std::chrono::seconds(SPEED));
		currentFllor--;
		std::cout << currentFllor << " ����: ���� ����������" << std::endl;
	}
	std::cout << currentFllor << " ����: ���� ������ �� �����" << std::endl;
}

void Engine::stop(std::thread &thread)
{
	if (thread.joinable())
	{
		thread.detach();
		std::cout << "���� ��� ����������" << std::endl;
	}
}