#ifndef AVM_OPERANDFACTORY_HPP
#define AVM_OPERANDFACTORY_HPP

#include "IOperand.hpp"

#include <string>

class OperandFactory
{
private:
	IOperand const * (OperandFactory::*creators[5])(std::string const & value) const;

	IOperand const * createInt8(std::string const & value) const;
	IOperand const * createInt16(std::string const & value) const;
	IOperand const * createInt32(std::string const & value) const;
	IOperand const * createFloat(std::string const & value) const;
	IOperand const * createDouble(std::string const & value) const;

public:
	IOperand const * createOperand(eOperandType type, std::string const & value) const;

	OperandFactory();
	OperandFactory(OperandFactory const & src);
	OperandFactory & operator=(OperandFactory const & rhs);
	~OperandFactory();
};

#endif
