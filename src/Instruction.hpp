#ifndef AVM_INSTRUCTION_HPP
#define AVM_INSTRUCTION_HPP

#include "InstructionType.hpp"
#include "IOperand.hpp"

#include <cstdint>

class Instruction
{
private:
	eInstructionType type;
	IOperand const * operand;
	uint32_t lineNum;

public:
	eInstructionType getType() const;
	IOperand const * getOperand() const;
	uint32_t getLineNum() const;

	Instruction();
	Instruction(eInstructionType type, uint32_t lineNum);
	Instruction(eInstructionType type, IOperand const * operand, uint32_t lineNum);
	Instruction(Instruction const & src);
	Instruction & operator=(Instruction const & rhs);
	~Instruction();
};

#endif
