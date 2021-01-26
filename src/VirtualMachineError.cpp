#include "VirtualMachineError.hpp"

VirtualMachineError::VirtualMachineError() : std::runtime_error("execution error") {}
