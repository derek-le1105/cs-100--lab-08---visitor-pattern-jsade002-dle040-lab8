#ifndef DIV
#define DIV

#include "../base.hpp"
#include "op.hpp"

class Div: public Base
{
	protected:
		double dividend, divisor, answer;
		std::string lString, rString, finalString;
	public:
		Div(Base* lh, Base* rh)
		{
			dividend = lh->evaluate();
			divisor = rh->evaluate();
			lString = lh->stringify();
			rString = rh->stringify();
		}
		
		virtual double evaluate()
		{
			answer = dividend / divisor;
			return answer;
		}
		
		virtual std::string stringify()
		{
			finalString = "(" + lString + " / " + rString + ")";
			return finalString;
		}
};
#endif

