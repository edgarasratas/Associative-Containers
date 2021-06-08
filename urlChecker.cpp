#include "lib.h"
#include "std.h"
#include "urlChecker.h"

bool urlChecker(const std::string& word)
{
	return std::regex_match(word,
		std::regex("^(http[s]?:\\/\\/(www\\.)?|\\/\\/(www\\.)?|www\\.){1}([0-9A-Za-z-\\.@:%_+~#=]+)+((\\.[a-zA-Z]{2,3})+)(/(.)*)?(\\?(.)*)?"));
}

bool urlChecker2(const std::string& word)
{
	return std::regex_match(word,
		std::regex("^([a-zA-Z0-9\\-\\.]+)\\.([a-zA-Z]{2,5})"));
}