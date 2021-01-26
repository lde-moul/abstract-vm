#include "OperandFactory.hpp"
#include "VirtualMachine.hpp"

void VirtualMachine::run()
{
	OperandFactory factory;

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
		{
			stack.dump();
			break;
		}
		case eInstructionType::assert:
			break;
		case eInstructionType::add:
			break;
		case eInstructionType::sub:
			break;
		case eInstructionType::mul:
			break;
		case eInstructionType::div:
			break;
		case eInstructionType::mod:
			break;
		case eInstructionType::print:
			break;
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
