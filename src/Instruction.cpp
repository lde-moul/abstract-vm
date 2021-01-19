#include "Instruction.hpp"

eInstructionType Instruction::getType() const
{
	return type;
}

IOperand const * Instruction::getOperand() const
{
	return operand;
}

Instruction::Instruction() : Instruction(eInstructionType::push) {}

Instruction::Instruction(eInstructionType type) : Instruction(type, nullptr) {}

Instruction::Instruction(eInstructionType type, IOperand const * operand) : type(type), operand(operand) {}

Instruction::Instruction(Instruction const & src)
{
	*this = src;
}

Instruction & Instruction::operator=(Instruction const & rhs)
{
	type = rhs.type;
	operand = rhs.operand;

	return *this;
}

Instruction::~Instruction() {}
