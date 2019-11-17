#include "AsyncFileIO.h"

AsyncFileIO::AsyncFileIO()
{
}

void AsyncFileIO::AsyncWriteToFile(std::string path, std::string text)
{
	std::thread fileWriter(&AsyncFileIO::WriteToFile, this, path, text);
	fileWriter.detach();
}

void AsyncFileIO::WriteToFile(std::string path, std::string text)
{
	std::lock_guard<std::mutex> fileGuard(fileMutex);

	std::fstream file(path, std::ios::app);
	file << text;
	file.close();
}
