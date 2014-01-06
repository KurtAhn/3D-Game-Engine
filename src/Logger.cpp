#include "Logger.h"

Logger *Logger::instance = nullptr;

Logger::Logger() {}

Logger::~Logger() {
    if (file.is_open()) file.close();
}

void Logger::openLog(const std::string &saveDirectory) {
    std::string filePath = saveDirectory + DIR_LOGS + FILE_LOG;
    CreateDirectory(filePath.c_str(), NULL);
    file.open(filePath, std::iostream::app);

    ASSERT(file.good(),
           "Log file couldn't be opened.");
}

void Logger::write(const std::string &message) {
    if (!file.good())
        throw IOException("Log file is not open.");

    // TODO: Add time of error.
    file << message << std::endl;
}

Logger *Logger::createInstance() {
    try {
        if (instance)
            throw std::runtime_error("'instance' member already exists.");
        instance = new Logger;
    } catch (const std::runtime_error &e) {
        RETHROW;
    }

    return instance;
}

Logger *Logger::getInstance() {
    return instance;
}

void Logger::destroy() {
    delete instance;
}
