#ifndef AVM_VIRTUALMACHINEERROR_HPP
#define AVM_VIRTUALMACHINEERROR_HPP

#include <stdexcept>
#include <string>

class VirtualMachineError : public std::runtime_error
{
public:
	VirtualMachineError();
	VirtualMachineError(std::string message);
};

class VirtualMachineOperationOverflowError : public VirtualMachineError
{
public:
	VirtualMachineOperationOverflowError();
};

class VirtualMachineOperationUnderflowError : public VirtualMachineError
{
public:
	VirtualMachineOperationUnderflowError();
};

class VirtualMachineZeroDivisionError : public VirtualMachineError
{
public:
	VirtualMachineZeroDivisionError();
};

class VirtualMachineEmptyStackError : public VirtualMachineError
{
public:
	VirtualMachineEmptyStackError();
};

class VirtualMachineAssertionError : public VirtualMachineError
{
public:
	VirtualMachineAssertionError();
};

class VirtualMachineTypeError : public VirtualMachineError
{
public:
	VirtualMachineTypeError();
};

class VirtualMachineRangeError : public VirtualMachineError
{
public:
	VirtualMachineRangeError();
};

#endif
