#ifndef AVM_VIRTUALMACHINEERROR_HPP
#define AVM_VIRTUALMACHINEERROR_HPP

#include <cstdint>
#include <stdexcept>
#include <string>

class VirtualMachineError : public std::runtime_error
{
public:
	VirtualMachineError();
	VirtualMachineError(std::string message, uint32_t lineNum);
};

class VirtualMachineOperationOverflowError : public VirtualMachineError
{
public:
	VirtualMachineOperationOverflowError(uint32_t lineNum);
};

class VirtualMachineOperationUnderflowError : public VirtualMachineError
{
public:
	VirtualMachineOperationUnderflowError(uint32_t lineNum);
};

class VirtualMachineZeroDivisionError : public VirtualMachineError
{
public:
	VirtualMachineZeroDivisionError(uint32_t lineNum);
};

class VirtualMachineEmptyStackError : public VirtualMachineError
{
public:
	VirtualMachineEmptyStackError(uint32_t lineNum);
};

class VirtualMachineNotEnoughOperandsError : public VirtualMachineError
{
public:
	VirtualMachineNotEnoughOperandsError(uint32_t lineNum);
};

class VirtualMachineAssertionError : public VirtualMachineError
{
public:
	VirtualMachineAssertionError(uint32_t lineNum);
};

class VirtualMachineTypeError : public VirtualMachineError
{
public:
	VirtualMachineTypeError(uint32_t lineNum);
};

class VirtualMachineRangeError : public VirtualMachineError
{
public:
	VirtualMachineRangeError(uint32_t lineNum);
};

#endif
