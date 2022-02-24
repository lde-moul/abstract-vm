#ifndef AVM_INT32_HPP
#define AVM_INT32_HPP

#include "IOperand.hpp"

#include <cstdint>

class Int32 : public IOperand
{
private:
	int32_t value;
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
	virtual bool operator<(IOperand const & rhs) const;

	virtual std::string const & toString() const;

	Int32();
	Int32(int32_t value);
	Int32(Int32 const & src);
	Int32 & operator=(Int32 const & rhs);
	~Int32();
};

#endif
