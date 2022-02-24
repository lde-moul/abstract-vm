#include "Float.hpp"
#include "OperandFactory.hpp"
#include "OperandError.hpp"

#include <cmath>

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
		float a = value;
		float b = std::stof(rhs.toString());
		float result = a + b;

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
	else
	{
		return rhs + *this;
	}
}

IOperand const * Float::operator-(IOperand const & rhs) const
{
	OperandFactory factory;
	std::string resultString;

	if (getPrecision() >= rhs.getPrecision())
	{
		float a = value;
		float b = std::stof(rhs.toString());
		float result = a - b;

		if (!std::isfinite(result))
		{
			if (result > 0)
				throw OperationOverflowError();
			else
				throw OperationUnderflowError();
		}

		resultString = std::to_string(result);
	}
	else if (rhs.getType() == eOperandType::Double)
	{
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

		resultString = std::to_string(result);
	}

	return factory.createOperand(getType(), resultString);
}

IOperand const * Float::operator*(IOperand const & rhs) const
{
	if (getPrecision() >= rhs.getPrecision())
	{
		OperandFactory factory;
		float a = value;
		float b = std::stof(rhs.toString());
		float result = a * b;

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
	else
	{
		return rhs * *this;
	}
}

IOperand const * Float::operator/(IOperand const & rhs) const
{
	OperandFactory factory;
	std::string resultString;

	if (getPrecision() >= rhs.getPrecision())
	{
		float a = value;
		float b = std::stof(rhs.toString());
		float result = a / b;

		if (!std::isfinite(result))
		{
			if (result > 0)
				throw OperationOverflowError();
			else
				throw OperationUnderflowError();
		}

		resultString = std::to_string(result);
	}
	else if (rhs.getType() == eOperandType::Double)
	{
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

		resultString = std::to_string(result);
	}

	return factory.createOperand(getType(), resultString);
}

IOperand const * Float::operator%(IOperand const & rhs) const
{
	OperandFactory factory;
	std::string resultString;

	if (getPrecision() >= rhs.getPrecision())
	{
		float a = value;
		float b = std::stof(rhs.toString());
		float result = std::fmod(a, b);

		if (!std::isfinite(result))
		{
			if (result > 0)
				throw OperationOverflowError();
			else
				throw OperationUnderflowError();
		}

		resultString = std::to_string(result);
	}
	else if (rhs.getType() == eOperandType::Double)
	{
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

		resultString = std::to_string(result);
	}

	return factory.createOperand(getType(), resultString);
}

IOperand const * Float::operator!() const
{
	OperandFactory factory;
	std::string resultString = std::to_string(!value);
	return factory.createOperand(getType(), resultString);
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
