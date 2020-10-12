#ifndef AVM_LEXERTOKEN_HPP
#define AVM_LEXERTOKEN_HPP

#include "LexerTokenType.hpp"

#include <string>

class LexerToken
{
private:
	eLexerTokenType type;
	std::string str;

public:
	eLexerTokenType getType() const;
	std::string const & getString() const;

	LexerToken();
	LexerToken(eLexerTokenType type, std::string const & str);
	LexerToken(LexerToken const & src);
	LexerToken & operator=(const LexerToken & rhs);
	~LexerToken();
};

#endif
