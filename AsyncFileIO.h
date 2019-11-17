#pragma once
#include <thread>
#include <mutex>
#include <iostream>
#include <fstream>

class AsyncFileIO
{
	std::mutex fileMutex;
	void WriteToFile(std::string path, std::string text);
public:
	AsyncFileIO();
	void AsyncWriteToFile(std::string path, std::string text);
};

