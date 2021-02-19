#include "VirtualMachineError.hpp"

VirtualMachineError::VirtualMachineError() : VirtualMachineError("execution error") {}

VirtualMachineError::VirtualMachineError(std::string message) : std::runtime_error(message) {}

VirtualMachineOperationOverflowError::VirtualMachineOperationOverflowError() : VirtualMachineError("operation overflow") {}

VirtualMachineOperationUnderflowError::VirtualMachineOperationUnderflowError() : VirtualMachineError("operation underflow") {}

VirtualMachineZeroDivisionError::VirtualMachineZeroDivisionError() : VirtualMachineError("division by zero") {}

VirtualMachineEmptyStackError::VirtualMachineEmptyStackError() : VirtualMachineError("empty stack") {}

VirtualMachineAssertionError::VirtualMachineAssertionError() : VirtualMachineError("assertion failure") {}

VirtualMachineTypeError::VirtualMachineTypeError() : VirtualMachineError("invalid type") {}

VirtualMachineRangeError::VirtualMachineRangeError() : VirtualMachineError("value out of range") {}
