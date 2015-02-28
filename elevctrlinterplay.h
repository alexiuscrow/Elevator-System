#ifndef ELEVCTRLINTERPLAY_H
#define ELEVCTRLINTERPLAY_H
#include<mutex>
#include <fstream>

class ElevCtrlInterplay
{
private:
	static std::mutex m_mace;
	static std::fstream m_logFile;
public:
	~ElevCtrlInterplay();
	std::mutex& getMace();
	std::fstream& getLogFile();
};

#endif