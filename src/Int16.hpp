#ifndef AVM_INT16_HPP
#define AVM_INT16_HPP

#include "IOperand.hpp"

#include <cstdint>

class Int16 : public IOperand
{
private:
	int16_t value;
	std::string str;

public:
	virtual int getPrecision() const;
	virtual eOperandType getType() const;

	virtual IOperand const * operator+(IOperand const & rhs) const;
	virtual IOperand const * operator-(IOperand const & rhs) const;
	virtual IOperand const * operator*(IOperand const & rhs) const;
	virtual IOperand const * operator/(IOperand const & rhs) const;
	virtual IOperand const * operator%(IOperand const & rhs) const;

	virtual std::string const & toString() const;

	Int16();
	Int16(int16_t value);
	Int16(Int16 const & src);
	Int16 & operator=(Int16 const & rhs);
	~Int16();
};

#endif
