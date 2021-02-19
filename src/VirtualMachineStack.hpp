#ifndef AVM_VIRTUALMACHINESTACK_HPP
#define AVM_VIRTUALMACHINESTACK_HPP

#include "IOperand.hpp"

#include <cstddef>
#include <vector>

class VirtualMachineStack
{
private:
	std::vector<IOperand const *> operands;

public:
	std::size_t getSize() const;
	void push(IOperand const * operand);
	IOperand const * pop();
	IOperand const * peek() const;
	void dump();

	VirtualMachineStack();
	VirtualMachineStack(VirtualMachineStack const & src);
	VirtualMachineStack & operator=(VirtualMachineStack const & rhs);
	~VirtualMachineStack();
};

#endif
