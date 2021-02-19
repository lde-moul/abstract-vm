#ifndef AVM_OPERANDERROR_HPP
#define AVM_OPERANDERROR_HPP

#include <stdexcept>

class OperandError : public std::runtime_error
{
public:
	OperandError();
};

class OperationOverflowError : public OperandError
{
public:
	OperationOverflowError();
};

class ZeroDivisionError : public OperandError
{
public:
	ZeroDivisionError();
};

class OperandRangeError : public OperandError
{
public:
	OperandRangeError();
};

#endif
