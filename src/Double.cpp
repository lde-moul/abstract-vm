#include "Double.hpp"
#include "OperandFactory.hpp"
#include "OperandError.hpp"

#include <cmath>

int Double::getPrecision() const
{
	return static_cast<int>(getType());
}

eOperandType Double::getType() const
{
	return eOperandType::Double;
}

IOperand const * Double::operator+(IOperand const & rhs) const
{
	OperandFactory factory;
	double a = value;
	double b = std::stod(rhs.toString());
	double result = a + b;

	if (!std::isfinite(result))
	{
		if (result > 0)
			throw OperationOverflowError();
		else
			throw OperationUnderflowError();
	}

	auto resultString = std::to_string(result);
	return factory.createOperand(getType(), resultString);
}

IOperand const * Double::operator-(IOperand const & rhs) const
{
	OperandFactory factory;
	double a = value;
	double b = std::stod(rhs.toString());
	double result = a - b;

	if (!std::isfinite(result))
	{
		if (result > 0)
			throw OperationOverflowError();
		else
			throw OperationUnderflowError();
	}

	auto resultString = std::to_string(result);

	return factory.createOperand(getType(), resultString);
}

IOperand const * Double::operator*(IOperand const & rhs) const
{
	OperandFactory factory;
	double a = value;
	double b = std::stod(rhs.toString());
	double result = a * b;

	if (!std::isfinite(result))
	{
		if (result > 0)
			throw OperationOverflowError();
		else
			throw OperationUnderflowError();
	}

	auto resultString = std::to_string(result);
	return factory.createOperand(getType(), resultString);
}

IOperand const * Double::operator/(IOperand const & rhs) const
{
	OperandFactory factory;
	double a = value;
	double b = std::stod(rhs.toString());
	double result = a / b;

	if (!std::isfinite(result))
	{
		if (result > 0)
			throw OperationOverflowError();
		else
			throw OperationUnderflowError();
	}

	auto resultString = std::to_string(result);

	return factory.createOperand(getType(), resultString);
}

IOperand const * Double::operator%(IOperand const & rhs) const
{
	OperandFactory factory;
	double a = value;
	double b = std::stod(rhs.toString());
	double result = std::fmod(a, b);

	if (!std::isfinite(result))
	{
		if (result > 0)
			throw OperationOverflowError();
		else
			throw OperationUnderflowError();
	}

	auto resultString = std::to_string(result);
	return factory.createOperand(getType(), resultString);
}

IOperand const * Double::operator!() const
{
	OperandFactory factory;
	auto resultString = std::to_string(!value);
	return factory.createOperand(getType(), resultString);
}

std::string const & Double::toString() const
{
	return str;
}

Double::Double() : Double(0) {}

Double::Double(double value) : value(value), str(std::to_string(value)) {}

Double::Double(Double const & src)
{
	*this = src;
}

Double & Double::operator=(Double const & rhs)
{
	value = rhs.value;
	str = rhs.str;

	return *this;
}

Double::~Double() {}
