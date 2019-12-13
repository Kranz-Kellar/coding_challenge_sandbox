#include "Logger.h"

using namespace Erbium;

bool Logger::consoleLog = false;

const char* Logger::logFileName = "default.txt";

AsyncFileIO Logger::asyncFileWriter;