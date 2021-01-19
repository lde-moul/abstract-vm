#include "Float.hpp"
#include "OperandFactory.hpp"

int Float::getPrecision() const
{
	return static_cast<int>(getType());
}

eOperandType Float::getType() const
{
	return eOperandType::Float;
}

IOperand const * Float::operator+(IOperand const & rhs) const
{
	if (getPrecision() >= rhs.getPrecision())
	{
		OperandFactory factory;
		auto otherValue = std::stof(rhs.toString());
		auto resultString = std::to_string(value + otherValue);
		return factory.createOperand(getType(), resultString);
	}
	else
	{
		return rhs + *this;
	}
}

IOperand const * Float::operator-(IOperand const & rhs) const
{
	if (getPrecision() >= rhs.getPrecision())
	{
		OperandFactory factory;
		auto otherValue = std::stof(rhs.toString());
		auto resultString = std::to_string(value + otherValue);
		return factory.createOperand(getType(), resultString);
	}
	else
	{
		return rhs + *this;
	}
}

IOperand const * Float::operator*(IOperand const & rhs) const
{
	if (getPrecision() >= rhs.getPrecision())
	{
		OperandFactory factory;
		auto otherValue = std::stof(rhs.toString());
		auto resultString = std::to_string(value + otherValue);
		return factory.createOperand(getType(), resultString);
	}
	else
	{
		return rhs + *this;
	}
}

IOperand const * Float::operator/(IOperand const & rhs) const
{
	if (getPrecision() >= rhs.getPrecision())
	{
		OperandFactory factory;
		auto otherValue = std::stof(rhs.toString());
		auto resultString = std::to_string(value + otherValue);
		return factory.createOperand(getType(), resultString);
	}
	else
	{
		return rhs + *this;
	}
}

IOperand const * Float::operator%(IOperand const & rhs) const
{
	if (getPrecision() >= rhs.getPrecision())
	{
		OperandFactory factory;
		auto otherValue = std::stof(rhs.toString());
		auto resultString = std::to_string(value + otherValue);
		return factory.createOperand(getType(), resultString);
	}
	else
	{
		return rhs + *this;
	}
}

std::string const & Float::toString() const
{
	return str;
}

Float::Float() : Float(0) {}

Float::Float(float value) : value(value), str(std::to_string(value)) {}

Float::Float(Float const & src)
{
	*this = src;
}

Float & Float::operator=(Float const & rhs)
{
	value = rhs.value;
	str = rhs.str;

	return *this;
}

Float::~Float() {}
