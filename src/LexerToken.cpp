#include "LexerToken.hpp"

eLexerTokenType LexerToken::getType() const
{
	return type;
}

std::string const & LexerToken::getString() const
{
	return str;
}

uint32_t LexerToken::getLineNum() const
{
	return lineNum;
}

LexerToken::LexerToken() : LexerToken(eLexerTokenType::none, "", 1) {}

LexerToken::LexerToken(eLexerTokenType type, std::string const & str, uint32_t lineNum) : type(type), str(str), lineNum(lineNum) {}

LexerToken::LexerToken(LexerToken const & src)
{
	*this = src;
}

LexerToken & LexerToken::operator=(LexerToken const & rhs)
{
	type = rhs.type;
	str = rhs.str;
	lineNum = rhs.lineNum;

	return *this;
}

LexerToken::~LexerToken() {}
