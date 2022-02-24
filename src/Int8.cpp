#include "Int8.hpp"
#include "OperandFactory.hpp"
#include "OperandError.hpp"

#include <cmath>

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
		int8_t a = value;
		int8_t b = std::stoi(rhs.toString());

		if (a >= 0 && b >= 0 && a > INT8_MAX - b)
			throw OperationOverflowError();
		else if (a < 0 && b < 0 && a < INT8_MIN - b)
			throw OperationUnderflowError();

		auto resultString = std::to_string(a + b);
		return factory.createOperand(getType(), resultString);
	}
	else
	{
		return rhs + *this;
	}
}

IOperand const * Int8::operator-(IOperand const & rhs) const
{
	OperandFactory factory;
	std::string resultString;

	if (getPrecision() >= rhs.getPrecision())
	{
		int8_t a = value;
		int8_t b = std::stoi(rhs.toString());

		if (a >= 0 && b < 0 && a > INT8_MAX + b)
			throw OperationOverflowError();
		else if (a < 0 && b >= 0 && a < INT8_MIN + b)
			throw OperationUnderflowError();

		resultString = std::to_string(a - b);
	}
	else if (rhs.getType() == eOperandType::Int16)
	{
		int16_t a = value;
		int16_t b = std::stoi(rhs.toString());

		if (a >= 0 && b < 0 && a > INT16_MAX + b)
			throw OperationOverflowError();
		else if (a < 0 && b >= 0 && a < INT16_MIN + b)
			throw OperationUnderflowError();

		resultString = std::to_string(a - b);
	}
	else if (rhs.getType() == eOperandType::Int32)
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

IOperand const * Int8::operator*(IOperand const & rhs) const
{
	if (getPrecision() >= rhs.getPrecision())
	{
		OperandFactory factory;
		int8_t a = value;
		int8_t b = std::stoi(rhs.toString());

		if ((a > 0) == (b > 0))
		{
			if ((a > 0 && a > INT8_MAX / b) || (a < 0 && a < INT8_MAX / b))
				throw OperationOverflowError();
		}
		else
		{
			if ((a < 0 && a < INT8_MIN / b) || (a > 0 && a > INT8_MIN / b))
				throw OperationUnderflowError();
		}

		auto resultString = std::to_string(a * b);
		return factory.createOperand(getType(), resultString);
	}
	else
	{
		return rhs * *this;
	}
}

IOperand const * Int8::operator/(IOperand const & rhs) const
{
	OperandFactory factory;
	std::string resultString;

	if (getPrecision() >= rhs.getPrecision())
	{
		int8_t a = value;
		int8_t b = std::stoi(rhs.toString());

		if (b == 0)
			throw ZeroDivisionError();
		else if (a == INT8_MIN && b == -1)
			throw OperationOverflowError();

		resultString = std::to_string(a / b);
	}
	else if (rhs.getType() == eOperandType::Int16)
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

IOperand const * Int8::operator%(IOperand const & rhs) const
{
	OperandFactory factory;
	std::string resultString;

	if (getPrecision() >= rhs.getPrecision())
	{
		int8_t a = value;
		int8_t b = std::stoi(rhs.toString());

		if (b == 0)
			throw ZeroDivisionError();

		resultString = std::to_string(a % b);
	}
	else if (rhs.getType() == eOperandType::Int16)
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

IOperand const * Int8::operator!() const
{
	OperandFactory factory;
	std::string resultString = std::to_string(!value);
	return factory.createOperand(getType(), resultString);
}

bool Int8::operator<(IOperand const & rhs) const
{
	if (getPrecision() >= rhs.getPrecision())
	{
		int8_t a = value;
		int8_t b = std::stoi(rhs.toString());
		return a < b;
	}
	else if (rhs.getType() == eOperandType::Int16)
	{
		int16_t a = value;
		int16_t b = std::stoi(rhs.toString());
		return a < b;
	}
	else if (rhs.getType() == eOperandType::Int32)
	{
		int32_t a = value;
		int32_t b = std::stoi(rhs.toString());
		return a < b;
	}
	else if (rhs.getType() == eOperandType::Float)
	{
		float a = value;
		float b = std::stof(rhs.toString());
		return a < b;
	}
	else if (rhs.getType() == eOperandType::Double)
	{
		double a = value;
		double b = std::stod(rhs.toString());
		return a < b;
	}
	else
	{
		return 0;
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
