#include "NullPointerException.h"

const std::string NullPointerException::NAME = "NullPointerException:\n\t";

NullPointerException::NullPointerException(const std::string &detail) :
    std::runtime_error(NAME + detail) {}

NullPointerException::~NullPointerException() throw() {}
