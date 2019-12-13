#pragma once
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include "AsyncFileIO.h"


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

		return "UNKNOW";
	}

	static void WriteMsgToFile(std::string path, std::string msg) {
		asyncFileWriter.AsyncWriteToFile(path, msg);
	}

	static const char* logFileName;
	static bool consoleLog;
	static AsyncFileIO asyncFileWriter;

	Logger();

public:

	static void Log(std::string msg, LogStatus status) {
		std::string fullMsg = "[" + LogStatusToString(status) + "]::" + msg + "\n";

		WriteMsgToFile(logFileName, fullMsg);

		if (consoleLog) {
			std::cout << fullMsg << std::endl;
		}
	}

	static void SetConsoleLog(bool value) {
		consoleLog = value;
	}

	static void SetLogFileName(const char* fileName) {
		logFileName = fileName;
	}
};
