#include "stdafx.h"
#include "elevctrlinterplay.h"
#include <string>

const std::string LOG_FILE_NAME = "logFile.txt";

std::mutex ElevCtrlInterplay::m_mace;
std::fstream ElevCtrlInterplay::m_logFile(LOG_FILE_NAME, std::fstream::out);

ElevCtrlInterplay::~ElevCtrlInterplay()
{
	m_logFile.close();
}

std::mutex& ElevCtrlInterplay::getMace()
{
	return m_mace;
}

std::fstream& ElevCtrlInterplay::getLogFile()
{
	return m_logFile;
}