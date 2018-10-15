
#ifndef String_Utils_h__
#define String_Utils_h__

#pragma once

#include <string>

#include <boost/algorithm/string.hpp>

int func()
{
std::string str("hello world! ");

boost::algorithm::trim_right(str);
}

#endif // String_Utils_h__
