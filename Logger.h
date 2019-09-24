#pragma once

#include <fstream>

enum LogStatus {
	LOG_DEBUG,
	LOG_INFO,
	LOG_WARNING,
	LOG_ERROR
};


class Logger
{
	static std::string LogStatusToString(LogStatus status) {
		switch (status) {
		case LOG_DEBUG:
			return "DEBUG";
		case LOG_INFO:
			return "INFO";
		case LOG_WARNING:
			return "WARNING";
		case LOG_ERROR:
			return "ERROR";
		}
	}

	static void WriteMsgToFile(std::string path, std::string msg) {
		std::ofstream logFile;
		logFile.open(path);
		logFile << msg;
		logFile.close();
	}

	static const char* logFileName;

public:
	static void Log(std::string msg, LogStatus status) {
		std::string fullMsg = "[" + LogStatusToString(status) + "]::" + msg;

		WriteMsgToFile(logFileName, fullMsg);
	}
};

