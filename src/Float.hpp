#ifndef AVM_FLOAT_HPP
#define AVM_FLOAT_HPP

#include "IOperand.hpp"

class Float : public IOperand
{
private:
	float value;
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

	Float();
	Float(float value);
	Float(Float const & src);
	Float & operator=(Float const & rhs);
	~Float();
};

#endif
