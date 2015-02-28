#include "stdafx.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <io.h>
#include <Windows.h>

void CreateConsole()
{
	using namespace std;
	//FreeConsole();
	//if (AllocConsole())
	//{
		int hCrt = _open_osfhandle((long)GetStdHandle(STD_OUTPUT_HANDLE), 4);
		*stdout = *(::_fdopen(hCrt, "w"));
		::setvbuf(stdout, NULL, _IONBF, 0);
		*stderr = *(::_fdopen(hCrt, "w"));
		::setvbuf(stderr, NULL, _IONBF, 0);
		std::ios::sync_with_stdio();
	//}
}

void printSmth(std::string str = "Text")
{
	std::cout << str << std::endl;
}

void doDo(std::string str = "Text")
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
	CreateConsole();
	printSmth(str);
	std::this_thread::sleep_for(std::chrono::seconds(3));
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	
	std::thread thf(doDo, "text 1");
	std::this_thread::sleep_for(std::chrono::seconds(2));
	printSmth("text 2");

	system("pause");
	
	return 0;
}



