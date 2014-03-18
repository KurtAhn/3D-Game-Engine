#include "NoSuchEntryException.h"

const std::string NoSuchEntryException::NAME = "NoSuchEntryException:\n\t";

NoSuchEntryException::NoSuchEntryException(const std::string &detail) :
    std::runtime_error(NAME + detail) {}

NoSuchEntryException::~NoSuchEntryException() throw() {}
