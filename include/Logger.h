#ifndef LOGGER_H
#define LOGGER_H

#include "Common.h"
#include "Exception.h"

class Logger {
public:
    Logger();
    ~Logger();

    void openLog(const std::string &saveDirectory);
    void write(const std::string &message);

    static Logger *createInstance();
    static Logger *getInstance();
    static void destroy();
private:
    static Logger *instance;
    std::ofstream file;
};

#endif // LOGGER_H
