#include "Int16.hpp"
#include "OperandFactory.hpp"
#include "OperandError.hpp"

#include <cmath>

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
		int16_t a = value;
		int16_t b = std::stoi(rhs.toString());

		if (a >= 0 && b >= 0 && a > INT16_MAX - b)
			throw OperationOverflowError();
		else if (a < 0 && b < 0 && a < INT16_MIN - b)
			throw OperationOverflowError();

		auto resultString = std::to_string(a + b);
		return factory.createOperand(getType(), resultString);
	}
	else
	{
		return rhs + *this;
	}
}

IOperand const * Int16::operator-(IOperand const & rhs) const
{
	OperandFactory factory;
	std::string resultString;

	if (getPrecision() >= rhs.getPrecision())
	{
		int16_t a = value;
		int16_t b = std::stoi(rhs.toString());

		if (a >= 0 && b < 0 && a > INT16_MAX + b)
			throw OperationOverflowError();
		else if (a < 0 && b >= 0 && a < INT16_MIN + b)
			throw OperationOverflowError();

		resultString = std::to_string(a - b);
	}
	else if (rhs.getType() == eOperandType::Int32)
	{
		int32_t a = value;
		int32_t b = std::stoi(rhs.toString());

		if (a >= 0 && b < 0 && a > INT32_MAX + b)
			throw OperationOverflowError();
		else if (a < 0 && b >= 0 && a < INT32_MIN + b)
			throw OperationOverflowError();

		resultString = std::to_string(a - b);
	}
	else if (rhs.getType() == eOperandType::Float)
	{
		float a = value;
		float b = std::stof(rhs.toString());
		float result = a - b;

		if (!std::isfinite(result))
			throw OperationOverflowError();

		resultString = std::to_string(result);
	}
	else if (rhs.getType() == eOperandType::Double)
	{
		double a = value;
		double b = std::stod(rhs.toString());
		double result = a - b;

		if (!std::isfinite(result))
			throw OperationOverflowError();

		resultString = std::to_string(result);
	}

	return factory.createOperand(getType(), resultString);
}

IOperand const * Int16::operator*(IOperand const & rhs) const
{
	if (getPrecision() >= rhs.getPrecision())
	{
		OperandFactory factory;
		int16_t a = value;
		int16_t b = std::stoi(rhs.toString());

		if ((a > 0) == (b > 0))
		{
			if ((a > 0 && a > INT16_MAX / b) || (a < 0 && a < INT16_MAX / b))
				throw OperationOverflowError();
		}
		else
		{
			if ((a < 0 && a < INT16_MIN / b) || (a > 0 && a > INT16_MIN / b))
				throw OperationOverflowError();
		}

		auto resultString = std::to_string(a * b);
		return factory.createOperand(getType(), resultString);
	}
	else
	{
		return rhs * *this;
	}
}

IOperand const * Int16::operator/(IOperand const & rhs) const
{
	OperandFactory factory;
	std::string resultString;

	if (getPrecision() >= rhs.getPrecision())
	{
		int16_t a = value;
		int16_t b = std::stoi(rhs.toString());

		if (b == 0)
			throw ZeroDivisionError();
		else if (a == INT16_MIN && b == -1)
			throw OperationOverflowError();

		resultString = std::to_string(a / b);
	}
	else if (rhs.getType() == eOperandType::Int32)
	{
		int32_t a = value;
		int32_t b = std::stoi(rhs.toString());

		if (b == 0)
			throw ZeroDivisionError();
		else if (a == INT32_MIN && b == -1)
			throw OperationOverflowError();

		resultString = std::to_string(a / b);
	}
	else if (rhs.getType() == eOperandType::Float)
	{
		float a = value;
		float b = std::stof(rhs.toString());
		float result = a / b;

		if (!std::isfinite(result))
			throw OperationOverflowError();

		resultString = std::to_string(result);
	}
	else if (rhs.getType() == eOperandType::Double)
	{
		double a = value;
		double b = std::stod(rhs.toString());
		double result = a / b;

		if (!std::isfinite(result))
			throw OperationOverflowError();

		resultString = std::to_string(result);
	}

	return factory.createOperand(getType(), resultString);
}

IOperand const * Int16::operator%(IOperand const & rhs) const
{
	OperandFactory factory;
	std::string resultString;

	if (getPrecision() >= rhs.getPrecision())
	{
		int16_t a = value;
		int16_t b = std::stoi(rhs.toString());

		if (b == 0)
			throw ZeroDivisionError();

		resultString = std::to_string(a % b);
	}
	else if (rhs.getType() == eOperandType::Int32)
	{
		int32_t a = value;
		int32_t b = std::stoi(rhs.toString());

		if (b == 0)
			throw ZeroDivisionError();

		resultString = std::to_string(a % b);
	}
	else if (rhs.getType() == eOperandType::Float)
	{
		float a = value;
		float b = std::stof(rhs.toString());
		float result = std::fmod(a, b);

		if (!std::isfinite(result))
			throw OperationOverflowError();

		resultString = std::to_string(result);
	}
	else if (rhs.getType() == eOperandType::Double)
	{
		double a = value;
		double b = std::stod(rhs.toString());
		double result = std::fmod(a, b);

		if (!std::isfinite(result))
			throw OperationOverflowError();

		resultString = std::to_string(result);
	}

	return factory.createOperand(getType(), resultString);
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
