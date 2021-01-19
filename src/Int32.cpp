#include "Int32.hpp"
#include "OperandFactory.hpp"

int Int32::getPrecision() const
{
	return static_cast<int>(getType());
}

eOperandType Int32::getType() const
{
	return eOperandType::Int32;
}

IOperand const * Int32::operator+(IOperand const & rhs) const
{
	if (getPrecision() >= rhs.getPrecision())
	{
		OperandFactory factory;
		auto otherValue = static_cast<int32_t>(std::stoi(rhs.toString()));
		auto resultString = std::to_string(value + otherValue);
		return factory.createOperand(getType(), resultString);
	}
	else
	{
		return rhs + *this;
	}
}

IOperand const * Int32::operator-(IOperand const & rhs) const
{
	if (getPrecision() >= rhs.getPrecision())
	{
		OperandFactory factory;
		auto otherValue = static_cast<int32_t>(std::stoi(rhs.toString()));
		auto resultString = std::to_string(value + otherValue);
		return factory.createOperand(getType(), resultString);
	}
	else
	{
		return rhs + *this;
	}
}

IOperand const * Int32::operator*(IOperand const & rhs) const
{
	if (getPrecision() >= rhs.getPrecision())
	{
		OperandFactory factory;
		auto otherValue = static_cast<int32_t>(std::stoi(rhs.toString()));
		auto resultString = std::to_string(value + otherValue);
		return factory.createOperand(getType(), resultString);
	}
	else
	{
		return rhs + *this;
	}
}

IOperand const * Int32::operator/(IOperand const & rhs) const
{
	if (getPrecision() >= rhs.getPrecision())
	{
		OperandFactory factory;
		auto otherValue = static_cast<int32_t>(std::stoi(rhs.toString()));
		auto resultString = std::to_string(value + otherValue);
		return factory.createOperand(getType(), resultString);
	}
	else
	{
		return rhs + *this;
	}
}

IOperand const * Int32::operator%(IOperand const & rhs) const
{
	if (getPrecision() >= rhs.getPrecision())
	{
		OperandFactory factory;
		auto otherValue = static_cast<int32_t>(std::stoi(rhs.toString()));
		auto resultString = std::to_string(value + otherValue);
		return factory.createOperand(getType(), resultString);
	}
	else
	{
		return rhs + *this;
	}
}

std::string const & Int32::toString() const
{
	return str;
}

Int32::Int32() : Int32(0) {}

Int32::Int32(int32_t value) : value(value), str(std::to_string(value)) {}

Int32::Int32(Int32 const & src)
{
	*this = src;
}

Int32 & Int32::operator=(Int32 const & rhs)
{
	value = rhs.value;
	str = rhs.str;

	return *this;
}

Int32::~Int32() {}
