#include "LexerToken.hpp"

eLexerTokenType LexerToken::getType() const
{
	return type;
}

std::string const & LexerToken::getString() const
{
	return str;
}

LexerToken::LexerToken() : LexerToken(eLexerTokenType::none, "") {}

LexerToken::LexerToken(eLexerTokenType type, std::string const & str) : type(type), str(str) {}

LexerToken::LexerToken(LexerToken const & src)
{
	*this = src;
}

LexerToken & LexerToken::operator=(LexerToken const & rhs)
{
	type = rhs.type;
	str = rhs.str;

	return *this;
}

LexerToken::~LexerToken() {}
