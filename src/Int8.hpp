#ifndef AVM_INT8_HPP
#define AVM_INT8_HPP

#include "IOperand.hpp"

#include <cstdint>

class Int8 : public IOperand
{
private:
	int8_t value;
	std::string str;

public:
	virtual int getPrecision() const;
	virtual eOperandType getType() const;

	virtual IOperand const * operator+(IOperand const & rhs) const;
	virtual IOperand const * operator-(IOperand const & rhs) const;
	virtual IOperand const * operator*(IOperand const & rhs) const;
	virtual IOperand const * operator/(IOperand const & rhs) const;
	virtual IOperand const * operator%(IOperand const & rhs) const;
	virtual IOperand const * operator!() const;

	virtual std::string const & toString() const;

	Int8();
	Int8(int8_t value);
	Int8(Int8 const & src);
	Int8 & operator=(Int8 const & rhs);
	~Int8();
};

#endif
