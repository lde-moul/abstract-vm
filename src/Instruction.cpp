#include "Instruction.hpp"

eInstructionType Instruction::getType() const
{
	return type;
}

IOperand const * Instruction::getOperand() const
{
	return operand;
}

uint32_t Instruction::getLineNum() const
{
	return lineNum;
}

Instruction::Instruction() : Instruction(eInstructionType::push, 1) {}

Instruction::Instruction(eInstructionType type, uint32_t lineNum) : Instruction(type, nullptr, lineNum) {}

Instruction::Instruction(eInstructionType type, IOperand const * operand, uint32_t lineNum) : type(type), operand(operand), lineNum(lineNum) {}

Instruction::Instruction(Instruction const & src)
{
	*this = src;
}

Instruction & Instruction::operator=(Instruction const & rhs)
{
	type = rhs.type;
	operand = rhs.operand;
	lineNum = rhs.lineNum;

	return *this;
}

Instruction::~Instruction()
{
	if (operand)
		delete operand;
}
