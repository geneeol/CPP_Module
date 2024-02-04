#include "RPNException.hpp"

RPNException::RPNException(const std::string &msg) throw() : msg(msg) {}
RPNException::~RPNException() throw() {}
const char *RPNException::what() const throw()
{
    return msg.c_str();
}