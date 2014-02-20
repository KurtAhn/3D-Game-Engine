#ifndef LOGGER_H
#define LOGGER_H

#include "Common.h"
#include "Directories.h"
#include "Exception.h"

class Logger {
public:
    Logger();
    ~Logger();

    void openLog(const std::string &saveDirectory);
    void write(const std::string &message);
    void write(const std::string &file, const int &line, const std::string &message);

    static Logger *createInstance();
    static Logger *getInstance();
    static void destroy();
private:
    static Logger *instance;
    std::ofstream output;
};

#endif // LOGGER_H
