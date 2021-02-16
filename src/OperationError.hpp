#ifndef AVM_OPERATIONERROR_HPP
#define AVM_OPERATIONERROR_HPP

#include <stdexcept>

class OperationOverflowError : public std::runtime_error
{
public:
	OperationOverflowError();
};

class ZeroDivisionError : public std::runtime_error
{
public:
	ZeroDivisionError();
};

#endif
