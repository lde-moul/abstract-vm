#ifndef AVM_LEXERTOKENTYPE_HPP
#define AVM_LEXERTOKENTYPE_HPP

enum class eLexerTokenType
{
	none,
	instruction,
	operandType,
	integerNumber,
	realNumber,
	openingBracket,
	closingBracket,
};

#endif
