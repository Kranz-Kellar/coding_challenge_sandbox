#include "Logger.h"

bool Logger::consoleLog = false;

const char* Logger::logFileName = "default.txt";

AsyncFileIO Logger::asyncFileWriter;