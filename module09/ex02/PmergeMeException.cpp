#include "PmergeMeException.hpp"

PmergeMeException::PmergeMeException(const std::string &msg) throw() : msg(msg) {}
PmergeMeException::~PmergeMeException() throw() {}
const char *PmergeMeException::what() const throw()
{
    return msg.c_str();
}