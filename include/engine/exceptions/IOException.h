#ifndef IOEXCEPTION_H
#define IOEXCEPTION_H

#include "ExceptionCommon.h"

class IOException : public std::runtime_error {
private:
    static const std::string NAME;
public:
    IOException() = delete;
    explicit IOException(const std::string &detail);
    virtual ~IOException() throw();
};

#endif // IOEXCEPTION_H
