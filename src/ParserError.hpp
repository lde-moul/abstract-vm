#ifndef AVM_PARSERERROR_HPP
#define AVM_PARSERERROR_HPP

#include <stdexcept>
#include <cstdint>

class ParserError : public std::runtime_error
{
public:
	ParserError();
	ParserError(uint32_t lineNum);
	ParserError(std::string message);
	ParserError(std::string message, uint32_t lineNum);
};

class ParserRangeError : public ParserError
{
public:
	ParserRangeError(uint32_t lineNum);
};

#endif
