#include "Lexer.hpp"
#include "LexerError.hpp"

#include <regex>
#include <string>
#include <cstdint>

bool Lexer::tryEatNextToken(std::string const & regexString, eLexerTokenType tokenType)
{
	std::regex regex(regexString);
	std::smatch match;

	if (std::regex_search(position, code.cend(), match, regex))
	{
		if (tokenType != eLexerTokenType::none)
			tokens.emplace_back(LexerToken(tokenType, match[1].str()));
		position = match[1].second;
 		return true;
	}
	else
	{
		return false;
	}
}

std::vector<LexerToken> const & Lexer::run()
{
	uint32_t lineNum = 1;

	while (true)
	{
		if (position == code.cend())
			break;
		else if (tryEatNextToken("^(\n)", eLexerTokenType::none))
			lineNum++;
		else if (tryEatNextToken("^(\\s+)", eLexerTokenType::none))
			continue;
		else if (tryEatNextToken("^(;.*?)\n?", eLexerTokenType::none))
			continue;
		else if (tryEatNextToken("^(push|pop|dump|assert|add|sub|mul|div|mod|print|exit)[^\\w]", eLexerTokenType::instruction))
			continue;
		else if (tryEatNextToken("^(int8|int16|int32|float|double)[^\\w]", eLexerTokenType::operandType))
			continue;
		else if (tryEatNextToken("^(\\-?\\d+)[^\\w]", eLexerTokenType::integerNumber))
			continue;
		else if (tryEatNextToken("^(\\-?\\d+\\.\\d+)[^\\w]", eLexerTokenType::realNumber))
			continue;
		else if (tryEatNextToken("^(\\()", eLexerTokenType::openingBracket))
			continue;
		else if (tryEatNextToken("^(\\))", eLexerTokenType::closingBracket))
			continue;
		else
			throw LexerError(lineNum);
	}

	return tokens;
}

Lexer::Lexer() : Lexer("") {}

Lexer::Lexer(std::string code) : code(code), position(this->code.cbegin()) {}

Lexer::Lexer(Lexer const & src)
{
	*this = src;
}

Lexer & Lexer::operator=(Lexer const & rhs)
{
	tokens = rhs.tokens;
	code = rhs.code;
	position = rhs.position;

	return *this;
}

Lexer::~Lexer() {}
