#include "Double.hpp"
#include "Float.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "OperandError.hpp"
#include "OperandFactory.hpp"

#include <cstdint>
#include <stdexcept>

IOperand const * OperandFactory::createInt8(std::string const & value) const
{
	int n;

	try
	{
		n = std::stoi(value);
	}
	catch (std::out_of_range & e)
	{
		throw OperandRangeError();
	}

	if (n < INT8_MIN || n > INT8_MAX)
		throw OperandRangeError();

	return new Int8(n);
}

IOperand const * OperandFactory::createInt16(std::string const & value) const
{
	int n;

	try
	{
		n = std::stoi(value);
	}
	catch (std::out_of_range & e)
	{
		throw OperandRangeError();
	}

	if (n < INT16_MIN || n > INT16_MAX)
		throw OperandRangeError();

	return new Int16(n);
}

IOperand const * OperandFactory::createInt32(std::string const & value) const
{
	int n;

	try
	{
		n = std::stoi(value);
	}
	catch (std::out_of_range & e)
	{
		throw OperandRangeError();
	}

	if (n < INT32_MIN || n > INT32_MAX)
		throw OperandRangeError();

	return new Int32(n);
}

IOperand const * OperandFactory::createFloat(std::string const & value) const
{
	int n;

	try
	{
		n = std::stof(value);
	}
	catch (std::out_of_range & e)
	{
		throw OperandRangeError();
	}

	return new Float(n);
}

IOperand const * OperandFactory::createDouble(std::string const & value) const
{
	int n;

	try
	{
		n = std::stod(value);
	}
	catch (std::out_of_range & e)
	{
		throw OperandRangeError();
	}

	return new Double(n);
}

IOperand const * OperandFactory::createOperand(eOperandType type, std::string const & value) const
{
	return (this->*(creators[static_cast<int>(type)]))(value);
}

OperandFactory::OperandFactory() : creators{
	&OperandFactory::createInt8,
	&OperandFactory::createInt16,
	&OperandFactory::createInt32,
	&OperandFactory::createFloat,
	&OperandFactory::createDouble,
}
{}

OperandFactory::OperandFactory(OperandFactory const & src)
{
	*this = src;
}

OperandFactory & OperandFactory::operator=(OperandFactory const & rhs)
{
	(void)rhs;

	return *this;
}

OperandFactory::~OperandFactory() {}
