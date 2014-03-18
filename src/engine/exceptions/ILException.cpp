#include "ILException.h"

const std::string ILException::NAME = "ILException:\n\t";

ILException::ILException(const std::string &detail) :
    std::runtime_error(NAME + detail) {}

ILException::~ILException() throw() {}
