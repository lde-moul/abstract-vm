#include "VirtualMachineError.hpp"

VirtualMachineError::VirtualMachineError() : VirtualMachineError("execution error") {}

VirtualMachineError::VirtualMachineError(std::string message) : std::runtime_error(message) {}

VirtualMachineError::VirtualMachineError(std::string message, uint32_t lineNum) : VirtualMachineError(message + " at line " + std::to_string(lineNum)) {}

VirtualMachineOperationOverflowError::VirtualMachineOperationOverflowError(uint32_t lineNum) : VirtualMachineError("operation overflow", lineNum) {}

VirtualMachineOperationUnderflowError::VirtualMachineOperationUnderflowError(uint32_t lineNum) : VirtualMachineError("operation underflow", lineNum) {}

VirtualMachineZeroDivisionError::VirtualMachineZeroDivisionError(uint32_t lineNum) : VirtualMachineError("division by zero", lineNum) {}

VirtualMachineEmptyStackError::VirtualMachineEmptyStackError(uint32_t lineNum) : VirtualMachineError("empty stack", lineNum) {}

VirtualMachineNotEnoughOperandsError::VirtualMachineNotEnoughOperandsError(uint32_t lineNum) : VirtualMachineError("not enough operands", lineNum) {}

VirtualMachineAssertionError::VirtualMachineAssertionError(uint32_t lineNum) : VirtualMachineError("assertion failure", lineNum) {}

VirtualMachineTypeError::VirtualMachineTypeError(uint32_t lineNum) : VirtualMachineError("invalid type", lineNum) {}

VirtualMachineRangeError::VirtualMachineRangeError(uint32_t lineNum) : VirtualMachineError("value out of range", lineNum) {}

VirtualMachineNoExitError::VirtualMachineNoExitError() : VirtualMachineError("reached end of program") {}
