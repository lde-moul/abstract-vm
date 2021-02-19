#include "OperandError.hpp"

OperandError::OperandError() : std::runtime_error("operand error") {}

OperationOverflowError::OperationOverflowError() {}

OperationUnderflowError::OperationUnderflowError() {}

ZeroDivisionError::ZeroDivisionError() {}

OperandRangeError::OperandRangeError() {}
