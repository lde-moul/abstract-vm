#ifndef AVM_VIRTUALMACHINESTACK_HPP
#define AVM_VIRTUALMACHINESTACK_HPP

#include "IOperand.hpp"

#include <vector>

class VirtualMachineStack
{
private:
	std::vector<IOperand const *> operands;

public:
	void push(IOperand const * operand);
	IOperand const * pop();
	void dump();

	VirtualMachineStack();
	VirtualMachineStack(VirtualMachineStack const & src);
	VirtualMachineStack & operator=(VirtualMachineStack const & rhs);
	~VirtualMachineStack();
};

#endif
