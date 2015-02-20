#include "stdafx.h"
#include <iostream>
#include <thread>
#include <chrono>

void doDo()
{
	std::cout << "Example Text! Thread ID = " << std::this_thread::get_id << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));
	system("pause");
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	
	std::thread thf(doDo);
	std::this_thread::sleep_for(std::chrono::seconds(2));
	doDo();
	//system("pause");
	
	return 0;
}



