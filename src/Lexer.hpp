#ifndef AVM_LEXER_HPP
#define AVM_LEXER_HPP

#include "LexerToken.hpp"

#include <cstdint>
#include <string>
#include <vector>

class Lexer
{
private:
	std::vector<LexerToken> tokens;
	std::string code;
	std::string::const_iterator position;
	uint32_t lineNum;

	bool tryEatNextToken(std::string const & regexString, eLexerTokenType tokenType);

public:
	std::vector<LexerToken> const & run();

	Lexer();
	Lexer(std::string code);
	Lexer(Lexer const & src);
	Lexer & operator=(Lexer const & rhs);
	~Lexer();
};

#endif
