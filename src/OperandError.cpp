#include "OperandError.hpp"

OperandError::OperandError() : std::runtime_error("operand error") {}

OperationOverflowError::OperationOverflowError() {}

ZeroDivisionError::ZeroDivisionError() {}

OperandRangeError::OperandRangeError() {}
