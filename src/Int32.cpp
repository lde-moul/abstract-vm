#include "Int32.hpp"
#include "OperandFactory.hpp"
#include "OperandError.hpp"

#include <cmath>

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
		int32_t a = value;
		int32_t b = std::stoi(rhs.toString());

		if (a >= 0 && b >= 0 && a > INT32_MAX - b)
			throw OperationOverflowError();
		else if (a < 0 && b < 0 && a < INT32_MIN - b)
			throw OperationUnderflowError();

		auto resultString = std::to_string(a + b);
		return factory.createOperand(getType(), resultString);
	}
	else
	{
		return rhs + *this;
	}
}

IOperand const * Int32::operator-(IOperand const & rhs) const
{
	OperandFactory factory;
	std::string resultString;

	if (getPrecision() >= rhs.getPrecision())
	{
		int32_t a = value;
		int32_t b = std::stoi(rhs.toString());

		if (a >= 0 && b < 0 && a > INT32_MAX + b)
			throw OperationOverflowError();
		else if (a < 0 && b >= 0 && a < INT32_MIN + b)
			throw OperationUnderflowError();

		resultString = std::to_string(a - b);
	}
	else if (rhs.getType() == eOperandType::Float)
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

IOperand const * Int32::operator*(IOperand const & rhs) const
{
	if (getPrecision() >= rhs.getPrecision())
	{
		OperandFactory factory;
		int32_t a = value;
		int32_t b = std::stoi(rhs.toString());

		if ((a > 0) == (b > 0))
		{
			if ((a > 0 && a > INT32_MAX / b) || (a < 0 && a < INT32_MAX / b))
				throw OperationOverflowError();
		}
		else
		{
			if ((a < 0 && a < INT32_MIN / b) || (a > 0 && a > INT32_MIN / b))
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

IOperand const * Int32::operator/(IOperand const & rhs) const
{
	OperandFactory factory;
	std::string resultString;

	if (getPrecision() >= rhs.getPrecision())
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

IOperand const * Int32::operator%(IOperand const & rhs) const
{
	OperandFactory factory;
	std::string resultString;

	if (getPrecision() >= rhs.getPrecision())
	{
		int32_t a = value;
		int32_t b = std::stoi(rhs.toString());

		if (b == 0)
			throw ZeroDivisionError();

		auto resultString = std::to_string(a % b);
		return factory.createOperand(getType(), resultString);
	}
	else if (rhs.getType() == eOperandType::Float)
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

IOperand const * Int32::operator!() const
{
	OperandFactory factory;
	std::string resultString = std::to_string(!value);
	return factory.createOperand(getType(), resultString);
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
