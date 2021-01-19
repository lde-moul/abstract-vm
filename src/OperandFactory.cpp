#include "OperandFactory.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"

IOperand const * OperandFactory::createInt8(std::string const & value) const
{
	return new Int8(std::stoi(value));
}

IOperand const * OperandFactory::createInt16(std::string const & value) const
{
	return new Int16(std::stoi(value));
}

IOperand const * OperandFactory::createInt32(std::string const & value) const
{
	return new Int32(std::stoi(value));
}

IOperand const * OperandFactory::createFloat(std::string const & value) const
{
	return new Float(std::stof(value));
}

IOperand const * OperandFactory::createDouble(std::string const & value) const
{
	return new Double(std::stod(value));
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
