#include "OperationError.hpp"

OperationOverflowError::OperationOverflowError() : std::runtime_error("operation overflow") {}

ZeroDivisionError::ZeroDivisionError() : std::runtime_error("division by zero") {}
