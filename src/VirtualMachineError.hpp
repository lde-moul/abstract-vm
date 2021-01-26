#ifndef AVM_VIRTUALMACHINEERROR_HPP
#define AVM_VIRTUALMACHINEERROR_HPP

#include <stdexcept>

class VirtualMachineError : public std::runtime_error
{
public:
	VirtualMachineError();
};

#endif
