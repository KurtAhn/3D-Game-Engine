#include "IOException.h"

const std::string IOException::NAME = "IOException:\n\t";

IOException::IOException(const std::string &detail) :
    std::runtime_error(NAME + detail) {}

IOException::~IOException() throw() {}
