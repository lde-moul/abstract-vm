#ifndef AVM_LEXER_HPP
#define AVM_LEXER_HPP

#include "LexerToken.hpp"

#include <vector>
#include <string>

class Lexer
{
private:
	std::vector<LexerToken> tokens;
	std::string code;
	std::string::const_iterator position;

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
