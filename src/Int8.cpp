#include "Int8.hpp"
#include "OperandFactory.hpp"

int Int8::getPrecision() const
{
	return static_cast<int>(getType());
}

eOperandType Int8::getType() const
{
	return eOperandType::Int8;
}

IOperand const * Int8::operator+(IOperand const & rhs) const
{
	if (getPrecision() >= rhs.getPrecision())
	{
		OperandFactory factory;
		auto otherValue = static_cast<int8_t>(std::stoi(rhs.toString()));
		auto resultString = std::to_string(value + otherValue);
		return factory.createOperand(getType(), resultString);
	}
	else
	{
		return rhs + *this;
	}
}

IOperand const * Int8::operator-(IOperand const & rhs) const
{
	if (getPrecision() >= rhs.getPrecision())
	{
		OperandFactory factory;
		auto otherValue = static_cast<int8_t>(std::stoi(rhs.toString()));
		auto resultString = std::to_string(value + otherValue);
		return factory.createOperand(getType(), resultString);
	}
	else
	{
		return rhs + *this;
	}
}

IOperand const * Int8::operator*(IOperand const & rhs) const
{
	if (getPrecision() >= rhs.getPrecision())
	{
		OperandFactory factory;
		auto otherValue = static_cast<int8_t>(std::stoi(rhs.toString()));
		auto resultString = std::to_string(value + otherValue);
		return factory.createOperand(getType(), resultString);
	}
	else
	{
		return rhs + *this;
	}
}

IOperand const * Int8::operator/(IOperand const & rhs) const
{
	if (getPrecision() >= rhs.getPrecision())
	{
		OperandFactory factory;
		auto otherValue = static_cast<int8_t>(std::stoi(rhs.toString()));
		auto resultString = std::to_string(value + otherValue);
		return factory.createOperand(getType(), resultString);
	}
	else
	{
		return rhs + *this;
	}
}

IOperand const * Int8::operator%(IOperand const & rhs) const
{
	if (getPrecision() >= rhs.getPrecision())
	{
		OperandFactory factory;
		auto otherValue = static_cast<int8_t>(std::stoi(rhs.toString()));
		auto resultString = std::to_string(value + otherValue);
		return factory.createOperand(getType(), resultString);
	}
	else
	{
		return rhs + *this;
	}
}

std::string const & Int8::toString() const
{
	return str;
}

Int8::Int8() : Int8(0) {}

Int8::Int8(int8_t value) : value(value), str(std::to_string(value)) {}

Int8::Int8(Int8 const & src)
{
	*this = src;
}

Int8 & Int8::operator=(Int8 const & rhs)
{
	value = rhs.value;
	str = rhs.str;

	return *this;
}

Int8::~Int8() {}
