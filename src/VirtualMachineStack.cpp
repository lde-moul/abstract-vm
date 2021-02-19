#include "VirtualMachineError.hpp"
#include "VirtualMachineStack.hpp"

#include <iostream>

std::size_t VirtualMachineStack::getSize() const
{
	return operands.size();
}

void VirtualMachineStack::push(IOperand const * operand)
{
	operands.push_back(operand);
}

IOperand const * VirtualMachineStack::pop()
{
	IOperand const * operand = peek();
	operands.pop_back();
	return operand;
}

IOperand const * VirtualMachineStack::peek() const
{
	IOperand const * operand = operands.back();
	return operand;
}

void VirtualMachineStack::dump()
{
	for (auto iter = operands.rbegin(); iter != operands.rend(); iter++)
		std::cout << (*iter)->toString() << std::endl;
}

VirtualMachineStack::VirtualMachineStack() {}

VirtualMachineStack::VirtualMachineStack(VirtualMachineStack const & src)
{
	*this = src;
}

VirtualMachineStack & VirtualMachineStack::operator=(VirtualMachineStack const & rhs)
{
	operands = rhs.operands;

	return *this;
}

VirtualMachineStack::~VirtualMachineStack()
{
	for (IOperand const * operand : operands)
		delete operand;
}
