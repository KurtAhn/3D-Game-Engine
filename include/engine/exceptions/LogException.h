#ifndef LOGEXCEPTION_H
#define LOGEXCEPTION_H

#include "ExceptionCommon.h"

class LogException : public std::runtime_error {
private:
    static const std::string NAME;
public:
    LogException() = delete;
    explicit LogException(const std::string &detail);
    virtual ~LogException() throw();
};

#endif // LOGEXCEPTION_H
