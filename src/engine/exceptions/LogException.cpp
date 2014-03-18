#include "LogException.h"

const std::string LogException::NAME = "LogException\n\t";

LogException::LogException(const std::string &detail) :
    std::runtime_error(NAME + detail) {}

LogException::~LogException() throw() {}
