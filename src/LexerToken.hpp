#ifndef AVM_LEXERTOKEN_HPP
#define AVM_LEXERTOKEN_HPP

#include "LexerTokenType.hpp"

#include <cstdint>
#include <string>

class LexerToken
{
private:
	eLexerTokenType type;
	std::string str;
	uint32_t lineNum;

public:
	eLexerTokenType getType() const;
	std::string const & getString() const;
	uint32_t getLineNum() const;

	LexerToken();
	LexerToken(eLexerTokenType type, std::string const & str, uint32_t lineNum);
	LexerToken(LexerToken const & src);
	LexerToken & operator=(LexerToken const & rhs);
	~LexerToken();
};

#endif
