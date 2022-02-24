#ifndef AVM_DOUBLE_HPP
#define AVM_DOUBLE_HPP

#include "IOperand.hpp"

class Double : public IOperand
{
private:
	double value;
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

	Double();
	Double(double value);
	Double(Double const & src);
	Double & operator=(Double const & rhs);
	~Double();
};

#endif
