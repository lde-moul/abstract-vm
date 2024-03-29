#include "OperandError.hpp"
#include "Parser.hpp"
#include "ParserError.hpp"

void Parser::assertTokenType(eLexerTokenType type) const
{
	if (currentToken == tokens.cend())
		throw ParserError();
	if (currentToken->getType() != type)
		throw ParserError(currentToken->getLineNum());
}

void Parser::assertTokenType(eLexerTokenType type1, eLexerTokenType type2) const
{
	if (currentToken == tokens.cend())
		throw ParserError();
	if (currentToken->getType() != type1 && currentToken->getType() != type2)
		throw ParserError(currentToken->getLineNum());
}

eInstructionType Parser::nameToInstructionType(std::string const & name) const
{
	if (name == "push")
		return eInstructionType::push;
	else if (name == "pop")
		return eInstructionType::pop;
	else if (name == "swap")
		return eInstructionType::swap;
	else if (name == "copy")
		return eInstructionType::copy;
	else if (name == "dump")
		return eInstructionType::dump;
	else if (name == "assert")
		return eInstructionType::assert;
	else if (name == "add")
		return eInstructionType::add;
	else if (name == "sub")
		return eInstructionType::sub;
	else if (name == "mul")
		return eInstructionType::mul;
	else if (name == "div")
		return eInstructionType::div;
	else if (name == "mod")
		return eInstructionType::mod;
	else if (name == "not")
		return eInstructionType::inv;
	else if (name == "min")
		return eInstructionType::min;
	else if (name == "max")
		return eInstructionType::max;
	else if (name == "print")
		return eInstructionType::print;
	else
		return eInstructionType::exit;
}

eOperandType Parser::nameToOperandType(std::string const & name) const
{
	if (name == "int8")
		return eOperandType::Int8;
	else if (name == "int16")
		return eOperandType::Int16;
	else if (name == "int32")
		return eOperandType::Int32;
	else if (name == "float")
		return eOperandType::Float;
	else
		return eOperandType::Double;
}

void Parser::parseOperandInstruction(eInstructionType instructionType)
{
	assertTokenType(eLexerTokenType::operandType);
	eOperandType operandType = nameToOperandType(currentToken->getString());
	currentToken++;

	assertTokenType(eLexerTokenType::openingBracket);
	currentToken++;

	assertTokenType(eLexerTokenType::integerNumber, eLexerTokenType::realNumber);
	auto valueToken = currentToken;
	currentToken++;

	assertTokenType(eLexerTokenType::closingBracket);
	currentToken++;

	try
	{
		IOperand const * operand = factory.createOperand(operandType, valueToken->getString());
		instructions.emplace_back(new Instruction(instructionType, operand, lineNum));
	}
	catch (OperandRangeError & e)
	{
		throw ParserRangeError(valueToken->getLineNum());
	}
}

std::vector<Instruction const *> const & Parser::run()
{
	currentToken = tokens.cbegin();

	while (currentToken != tokens.cend())
	{
		lineNum = currentToken->getLineNum();

		assertTokenType(eLexerTokenType::instruction);
		eInstructionType instructionType = nameToInstructionType(currentToken->getString());
		currentToken++;

		if (instructionType == eInstructionType::push || instructionType == eInstructionType::assert)
			parseOperandInstruction(instructionType);
		else
			instructions.emplace_back(new Instruction(instructionType, lineNum));
	}

	return instructions;
}

Parser::Parser() {}

Parser::Parser(std::vector<LexerToken> tokens) : tokens(tokens) {}

Parser::Parser(Parser const & src)
{
	*this = src;
}

Parser & Parser::operator=(Parser const & rhs)
{
	instructions = rhs.instructions;
	tokens = rhs.tokens;
	currentToken = rhs.currentToken;
	lineNum = rhs.lineNum;

	return *this;
}

Parser::~Parser()
{
	for (Instruction const * instruction : instructions)
		delete instruction;
}
