#pragma once

#include <iostream>
#include <fstream>
#include "Logger.h"

namespace Erbium {

	class FileIO
	{
		static std::fstream file;
	public:
		static std::string ReadFile(std::string pathToFile) {
			Logger::Log("FileIO::Implementation not found", LOG_WARNING);
		}
		static void WriteToFile(std::string pathToFile) {
			Logger::Log("FileIO::Implementation not found", LOG_WARNING);
		}
		static void WriteToFileAsync(std::string pathToFile) {
			Logger::Log("FileIO::Implementation not found", LOG_WARNING);
		}
	};

}
