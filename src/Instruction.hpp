#ifndef AVM_INSTRUCTION_HPP
#define AVM_INSTRUCTION_HPP

#include "InstructionType.hpp"
#include "IOperand.hpp"

class Instruction
{
private:
	eInstructionType type;
	IOperand const * operand;

public:
	eInstructionType getType() const;
	IOperand const * getOperand() const;

	Instruction();
	Instruction(eInstructionType type);
	Instruction(eInstructionType type, IOperand const * operand);
	Instruction(Instruction const & src);
	Instruction & operator=(Instruction const & rhs);
	~Instruction();
};

#endif
