#include "Logger.h"

Logger *Logger::instance = nullptr;

Logger::Logger() {}

Logger::~Logger() {
    if (output.is_open())
        output.close();
}

void Logger::openLog(const std::string &saveDirectory) {
    std::string logDirectory = saveDirectory + DIR_LOGS;
    std::string logFile = logDirectory + FILE_LOG;
    FileSystem::createDirectory(logDirectory);
    output.open(logFile, std::iostream::app);

    if (!output.good()) {
        std::ifstream input(logFile);
        output.open(logFile, std::iostream::app);
    }

    ASSERT(output.good(),
           std::string("Log file couldn't be opened at ") + logFile);
}

void Logger::write(const std::string &message) {
    if (!output.good())
        throw IOException("Log file is not open.");

    // TODO: Add time of error.
    output << "Message: " << message << std::endl;
}

void Logger::write(const std::string &file, const int &line, const std::string &message) {
    if (!output.good())
        throw IOException("Log file is not open.");

    // TODO: Add time of error.
    output << "In file: " << file << std::endl
           << "In line: " << line << std::endl
           << "Message: " << message << std::endl << std::endl;
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
