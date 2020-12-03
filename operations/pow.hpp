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
	Base* left;
	Base* right;
public:
	Pow(Base* lh, Base* rh)
	{
		left = lh; 
		right = rh;
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
	virtual Iterator* create_iterator(){
        Iterator* test = new BinaryIterator(this);
		return test;
    }

	virtual Base* get_left(){
		return left;
    }

    virtual Base* get_right(){
        return right;
    }

};

#endif
