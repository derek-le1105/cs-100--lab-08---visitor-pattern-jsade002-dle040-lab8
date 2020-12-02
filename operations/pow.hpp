#ifndef POW
#define POW

#include "../base.hpp"
#include "op.hpp"
#include <cmath>

class Pow : public Base
{
    protected:
	double base, exponent, answer;
	std::string lString, rString, finalString;
    public:
	Pow(Base* lh, Base* rh)
	{
	    base = lh->evaluate();
	    exponent = rh->evaluate();
	    lString = lh->stringify();
	    rString = rh->stringify();
	}
	    

	virtual double evaluate()
	{
	    answer = pow(base, exponent);
	    return answer;
	}

	virtual std::string stringify()
	{
	    finalString = "(" + lString + " ** " + rString + ")";
	    return finalString;
	}

};

#endif
