#include "Logger.h"

Logger *Logger::instance = nullptr;

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

Logger::Logger() {}

Logger::~Logger() {
    if (output.is_open())
        output.close();
}

void Logger::open(const std::string &logFilePath) {
    try {
        output.open(logFilePath, std::iostream::app);

        if (!output)
            throw LogException("Cannot open log file at " + logFilePath);
    } catch (LogException &e) {
        std::cerr << e.what() << std::endl;
        exit(-1);
    }
}

void Logger::write(const std::string &message) {
    ASSERT(output.good(),
           "Log file is not open.");

    // TODO: Add time of error.
    output << "Message: " << message << std::endl;
}

void Logger::write(const std::string &file,
                   const int &line,
                   const std::string &message) {
    ASSERT(output.good(),
           "Log file is not open.");

    // TODO: Add time of error.
    output << "In file: " << file << std::endl
           << "In line: " << line << std::endl
           << "Message: " << message << std::endl << std::endl;
}
