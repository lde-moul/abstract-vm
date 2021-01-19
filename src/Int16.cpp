#include "Int16.hpp"
#include "OperandFactory.hpp"

int Int16::getPrecision() const
{
	return static_cast<int>(getType());
}

eOperandType Int16::getType() const
{
	return eOperandType::Int16;
}

IOperand const * Int16::operator+(IOperand const & rhs) const
{
	if (getPrecision() >= rhs.getPrecision())
	{
		OperandFactory factory;
		auto otherValue = static_cast<int16_t>(std::stoi(rhs.toString()));
		auto resultString = std::to_string(value + otherValue);
		return factory.createOperand(getType(), resultString);
	}
	else
	{
		return rhs + *this;
	}
}

IOperand const * Int16::operator-(IOperand const & rhs) const
{
	if (getPrecision() >= rhs.getPrecision())
	{
		OperandFactory factory;
		auto otherValue = static_cast<int16_t>(std::stoi(rhs.toString()));
		auto resultString = std::to_string(value + otherValue);
		return factory.createOperand(getType(), resultString);
	}
	else
	{
		return rhs + *this;
	}
}

IOperand const * Int16::operator*(IOperand const & rhs) const
{
	if (getPrecision() >= rhs.getPrecision())
	{
		OperandFactory factory;
		auto otherValue = static_cast<int16_t>(std::stoi(rhs.toString()));
		auto resultString = std::to_string(value + otherValue);
		return factory.createOperand(getType(), resultString);
	}
	else
	{
		return rhs + *this;
	}
}

IOperand const * Int16::operator/(IOperand const & rhs) const
{
	if (getPrecision() >= rhs.getPrecision())
	{
		OperandFactory factory;
		auto otherValue = static_cast<int16_t>(std::stoi(rhs.toString()));
		auto resultString = std::to_string(value + otherValue);
		return factory.createOperand(getType(), resultString);
	}
	else
	{
		return rhs + *this;
	}
}

IOperand const * Int16::operator%(IOperand const & rhs) const
{
	if (getPrecision() >= rhs.getPrecision())
	{
		OperandFactory factory;
		auto otherValue = static_cast<int16_t>(std::stoi(rhs.toString()));
		auto resultString = std::to_string(value + otherValue);
		return factory.createOperand(getType(), resultString);
	}
	else
	{
		return rhs + *this;
	}
}

std::string const & Int16::toString() const
{
	return str;
}

Int16::Int16() : Int16(0) {}

Int16::Int16(int16_t value) : value(value), str(std::to_string(value)) {}

Int16::Int16(Int16 const & src)
{
	*this = src;
}

Int16 & Int16::operator=(Int16 const & rhs)
{
	value = rhs.value;
	str = rhs.str;

	return *this;
}

Int16::~Int16() {}
