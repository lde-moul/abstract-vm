#include "OperandFactory.hpp"
#include "VirtualMachine.hpp"
#include "VirtualMachineError.hpp"

#include <iostream>
#include <string>

void VirtualMachine::popOperandPair(IOperand const * & op1, IOperand const * & op2)
{
	op1 = stack.pop();
	op2 = stack.pop();
}

void VirtualMachine::run()
{
	OperandFactory factory;
	IOperand const * op1, * op2, * result;

	for (Instruction const * instruction : instructions)
	{
		switch (instruction->getType())
		{
		case eInstructionType::push:
		{
			IOperand const * operand = instruction->getOperand();
			IOperand const * newOperand = factory.createOperand(operand->getType(), operand->toString());
			stack.push(newOperand);
			break;
		}
		case eInstructionType::pop:
			stack.pop();
			break;
		case eInstructionType::dump:
			stack.dump();
			break;
		case eInstructionType::assert:
			break;
		case eInstructionType::add:
			popOperandPair(op1, op2);
			result = *op2 + *op1;
			stack.push(result);
			break;
		case eInstructionType::sub:
			popOperandPair(op1, op2);
			result = *op2 - *op1;
			stack.push(result);
			break;
		case eInstructionType::mul:
			popOperandPair(op1, op2);
			result = *op2 * *op1;
			stack.push(result);
			break;
		case eInstructionType::div:
			popOperandPair(op1, op2);
			result = *op2 / *op1;
			stack.push(result);
			break;
		case eInstructionType::mod:
			popOperandPair(op1, op2);
			result = *op2 % *op1;
			stack.push(result);
			break;
		case eInstructionType::print:
		{
			IOperand const * operand = stack.peek();
			if (operand->getType() != eOperandType::Int8)
				throw VirtualMachineError();
			signed char c = std::stoi(operand->toString());
			if (c < 0)
				throw VirtualMachineError();
			std::cout << c << std::endl;
			break;
		}
		case eInstructionType::exit:
			break;
		}
	}
}

VirtualMachine::VirtualMachine() {}

VirtualMachine::VirtualMachine(std::vector<Instruction const *> instructions) : instructions(instructions) {}

VirtualMachine::VirtualMachine(VirtualMachine const & src)
{
	*this = src;
}

VirtualMachine & VirtualMachine::operator=(VirtualMachine const & rhs)
{
	instructions = rhs.instructions;
	stack = rhs.stack;

	return *this;
}

VirtualMachine::~VirtualMachine() {}
