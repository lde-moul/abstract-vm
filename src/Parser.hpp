#ifndef AVM_PARSER_HPP
#define AVM_PARSER_HPP

#include "Instruction.hpp"
#include "LexerToken.hpp"
#include "OperandFactory.hpp"
#include "OperandType.hpp"

#include <vector>

class Parser
{
private:
	std::vector<Instruction> instructions;
	std::vector<LexerToken> tokens;
	std::vector<LexerToken>::const_iterator currentToken = tokens.cbegin();
	OperandFactory factory;

	void assertTokenType(eLexerTokenType type) const;
	void assertTokenType(eLexerTokenType type1, eLexerTokenType type2) const;
	eInstructionType nameToInstructionType(std::string const & name) const;
	eOperandType nameToOperandType(std::string const & name) const;
	void parseOperandInstruction(eInstructionType instructionType);

public:
	std::vector<Instruction> const & run();

	Parser();
	Parser(std::vector<LexerToken> tokens);
	Parser(Parser const & src);
	Parser & operator=(Parser const & rhs);
	~Parser();
};

#endif
