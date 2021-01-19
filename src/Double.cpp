#include "Double.hpp"
#include "OperandFactory.hpp"

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
	if (getPrecision() >= rhs.getPrecision())
	{
		OperandFactory factory;
		auto otherValue = std::stod(rhs.toString());
		auto resultString = std::to_string(value + otherValue);
		return factory.createOperand(getType(), resultString);
	}
	else
	{
		return rhs + *this;
	}
}

IOperand const * Double::operator-(IOperand const & rhs) const
{
	if (getPrecision() >= rhs.getPrecision())
	{
		OperandFactory factory;
		auto otherValue = std::stod(rhs.toString());
		auto resultString = std::to_string(value + otherValue);
		return factory.createOperand(getType(), resultString);
	}
	else
	{
		return rhs + *this;
	}
}

IOperand const * Double::operator*(IOperand const & rhs) const
{
	if (getPrecision() >= rhs.getPrecision())
	{
		OperandFactory factory;
		auto otherValue = std::stod(rhs.toString());
		auto resultString = std::to_string(value + otherValue);
		return factory.createOperand(getType(), resultString);
	}
	else
	{
		return rhs + *this;
	}
}

IOperand const * Double::operator/(IOperand const & rhs) const
{
	if (getPrecision() >= rhs.getPrecision())
	{
		OperandFactory factory;
		auto otherValue = std::stod(rhs.toString());
		auto resultString = std::to_string(value + otherValue);
		return factory.createOperand(getType(), resultString);
	}
	else
	{
		return rhs + *this;
	}
}

IOperand const * Double::operator%(IOperand const & rhs) const
{
	if (getPrecision() >= rhs.getPrecision())
	{
		OperandFactory factory;
		auto otherValue = std::stod(rhs.toString());
		auto resultString = std::to_string(value + otherValue);
		return factory.createOperand(getType(), resultString);
	}
	else
	{
		return rhs + *this;
	}
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
