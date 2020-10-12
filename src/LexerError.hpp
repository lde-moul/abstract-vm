#ifndef AVM_LEXERERROR_HPP
#define AVM_LEXERERROR_HPP

#include <stdexcept>
#include <cstdint>

class LexerError : public std::runtime_error
{
public:
	LexerError(uint32_t lineNum);
};

#endif
