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
	for (Instruction const * instruction : instructions)
	{
		OperandFactory factory;
		IOperand const * op1 = nullptr;
		IOperand const * op2 = nullptr;
		IOperand const * result = nullptr;

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

				delete stack.pop();
				break;
			case eInstructionType::swap:
				popOperandPair(op1, op2, instruction);
				stack.push(op1);
				stack.push(op2);
				break;
			case eInstructionType::copy:
			{
				if (stack.getSize() < 1)
					throw VirtualMachineEmptyStackError(instruction->getLineNum());

				IOperand const * operand = stack.peek();
				IOperand const * newOperand = factory.createOperand(operand->getType(), operand->toString());
				stack.push(newOperand);
				break;
			}
			case eInstructionType::dump:
				stack.dump();
				break;
			case eInstructionType::assert:
				if (stack.getSize() < 1)
					throw VirtualMachineAssertionError(instruction->getLineNum());
				op1 = stack.peek();
				op2 = instruction->getOperand();
				if (op1->getType() != op2->getType() || op1->toString() != op2->toString())
					throw VirtualMachineAssertionError(instruction->getLineNum());
				break;
			case eInstructionType::add:
				popOperandPair(op1, op2, instruction);
				result = *op2 + *op1;
				stack.push(result);
				delete op1;
				delete op2;
				break;
			case eInstructionType::sub:
				popOperandPair(op1, op2, instruction);
				result = *op2 - *op1;
				stack.push(result);
				delete op1;
				delete op2;
				break;
			case eInstructionType::mul:
				popOperandPair(op1, op2, instruction);
				result = *op2 * *op1;
				stack.push(result);
				delete op1;
				delete op2;
				break;
			case eInstructionType::div:
				popOperandPair(op1, op2, instruction);
				result = *op2 / *op1;
				stack.push(result);
				delete op1;
				delete op2;
				break;
			case eInstructionType::mod:
				popOperandPair(op1, op2, instruction);
				result = *op2 % *op1;
				stack.push(result);
				delete op1;
				delete op2;
				break;
			case eInstructionType::inv:
				if (stack.getSize() < 1)
					throw VirtualMachineNotEnoughOperandsError(instruction->getLineNum());
				op1 = stack.pop();
				result = !(*op1);
				stack.push(result);
				delete op1;
				break;
			case eInstructionType::min:
				popOperandPair(op1, op2, instruction);
				if (*op1 < *op2)
				{
					stack.push(op1);
					delete op2;
				}
				else
				{
					stack.push(op2);
					delete op1;
				}
				break;
			case eInstructionType::max:
				popOperandPair(op1, op2, instruction);
				if (*op2 < *op1)
				{
					stack.push(op1);
					delete op2;
				}
				else
				{
					stack.push(op2);
					delete op1;
				}
				break;
			case eInstructionType::print:
			{
				if (stack.getSize() < 1)
					throw VirtualMachineEmptyStackError(instruction->getLineNum());
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
			delete op1;
			delete op2;

			throw VirtualMachineOperationOverflowError(instruction->getLineNum());
		}
		catch (OperationUnderflowError & e)
		{
			delete op1;
			delete op2;

			throw VirtualMachineOperationUnderflowError(instruction->getLineNum());
		}
		catch (ZeroDivisionError & e)
		{
			delete op1;
			delete op2;

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

VirtualMachine::~VirtualMachine()
{
	for (Instruction const * instruction : instructions)
		delete instruction;
}
