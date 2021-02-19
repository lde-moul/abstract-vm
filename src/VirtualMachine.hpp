#ifndef AVM_VIRTUALMACHINE_HPP
#define AVM_VIRTUALMACHINE_HPP

#include "Instruction.hpp"
#include "VirtualMachineStack.hpp"

#include <vector>

class VirtualMachine
{
private:
	std::vector<Instruction const *> instructions;
	VirtualMachineStack stack;

	void popOperandPair(IOperand const * & op1, IOperand const * & op2, Instruction const * instruction);

public:
	void run();

	VirtualMachine();
	VirtualMachine(std::vector<Instruction const *> instructions);
	VirtualMachine(VirtualMachine const & src);
	VirtualMachine & operator=(VirtualMachine const & rhs);
	~VirtualMachine();
};

#endif
