#include "AsyncFileIO.h"

using namespace Erbium;

void AsyncFileIO::WriteText(const std::string& path, const std::string& text)
{
	std::thread thr(&AsyncFileIO::WriteThread, this, path, text);
	thr.detach();
}

bool AsyncFileIO::isFileExists(const std::string& path)
{
	if (FILE* file = fopen(path.c_str(), "r")) {
		fclose(file);
		return true;
	}
	else {
		return false;
	}
}

void AsyncFileIO::WriteThread(const std::string& path, const std::string& text)
{
	std::lock_guard<std::mutex> fileGuard(fileMutex);

	std::ofstream file(path, std::ios::app);
	file << text;
	file.close();
}