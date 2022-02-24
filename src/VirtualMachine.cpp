#include "OperandFactory.hpp"
#include "OperandError.hpp"
#include "VirtualMachine.hpp"
#include "VirtualMachineError.hpp"

#include <iostream>
#include <string>

void VirtualMachine::popOperandPair(IOperand const * & op1, IOperand const * & op2, Instruction const * instruction)
{
	if (stack.getSize() < 2)
		throw VirtualMachineNotEnoughOperandsError(instruction->getLineNum());

	op1 = stack.pop();
	op2 = stack.pop();
}

void VirtualMachine::run()
{
	OperandFactory factory;
	IOperand const * op1, * op2, * result;

	for (Instruction const * instruction : instructions)
	{
		try
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
				if (stack.getSize() < 1)
					throw VirtualMachineEmptyStackError(instruction->getLineNum());

				stack.pop();
				break;
			case eInstructionType::swap:
				popOperandPair(op1, op2, instruction);
				stack.push(op1);
				stack.push(op2);
				break;
			case eInstructionType::dump:
				stack.dump();
				break;
			case eInstructionType::assert:
				op1 = stack.peek();
				op2 = instruction->getOperand();
				if (op1->getType() != op2->getType() || op1->toString() != op2->toString())
					throw VirtualMachineAssertionError(instruction->getLineNum());
				break;
			case eInstructionType::add:
				popOperandPair(op1, op2, instruction);
				result = *op2 + *op1;
				stack.push(result);
				break;
			case eInstructionType::sub:
				popOperandPair(op1, op2, instruction);
				result = *op2 - *op1;
				stack.push(result);
				break;
			case eInstructionType::mul:
				popOperandPair(op1, op2, instruction);
				result = *op2 * *op1;
				stack.push(result);
				break;
			case eInstructionType::div:
				popOperandPair(op1, op2, instruction);
				result = *op2 / *op1;
				stack.push(result);
				break;
			case eInstructionType::mod:
				popOperandPair(op1, op2, instruction);
				result = *op2 % *op1;
				stack.push(result);
				break;
			case eInstructionType::inv:
				if (stack.getSize() < 1)
					throw VirtualMachineNotEnoughOperandsError(instruction->getLineNum());
				op1 = stack.pop();
				result = !(*op1);
				stack.push(result);
				break;
			case eInstructionType::print:
			{
				IOperand const * operand = stack.peek();
				if (operand->getType() != eOperandType::Int8)
					throw VirtualMachineTypeError(instruction->getLineNum());
				signed char c = std::stoi(operand->toString());
				if (c < 0)
					throw VirtualMachineRangeError(instruction->getLineNum());
				std::cout << c << std::endl;
				break;
			}
			case eInstructionType::exit:
				return;
				break;
			}
		}
		catch (OperationOverflowError & e)
		{
			throw VirtualMachineOperationOverflowError(instruction->getLineNum());
		}
		catch (OperationUnderflowError & e)
		{
			throw VirtualMachineOperationUnderflowError(instruction->getLineNum());
		}
		catch (ZeroDivisionError & e)
		{
			throw VirtualMachineZeroDivisionError(instruction->getLineNum());
		}
	}

	throw VirtualMachineNoExitError();
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
