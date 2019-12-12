#pragma once
#include <thread>
#include <mutex>
#include <iostream>
#include <fstream>
#include <stdio.h>

namespace Erbium {

	class AsyncFileIO
	{
		std::mutex fileMutex;


		bool isFileExists(const std::string& path);
		void WriteThread(const std::string& path, const std::string& text);
	public:
		void WriteText(const std::string& path, const std::string& text);
	};

}
