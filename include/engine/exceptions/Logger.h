#ifndef LOGGER_H
#define LOGGER_H

#include "ExceptionCommon.h"

#ifndef NDEBUG
    #define LOG_ERROR(e) std::cerr << __FILE__ << std::endl\
                                   << __LINE__ << std::endl\
                                   << e.what() << std::endl << std::endl;
#else
    #define LOG_ERROR(e) Logger::getInstance()->write(__FILE__, __LINE__, e.what())
#endif

#ifndef NRETHROW
    #define RETHROW throw
#else
    #define RETRHOW
#endif

#include "LogException.h"

class Logger {
private:
    static Logger *instance;

public:
    static Logger *createInstance();
    static Logger *getInstance();
    static void destroy();

public:
    Logger();
    ~Logger();

public:
    void open(const std::string &logFilePath);
    void write(const std::string &message);
    void write(const std::string &file,
               const int &line,
               const std::string &message);

private:
    std::ofstream output;
};

#endif // LOGGER_H
