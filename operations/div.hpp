#ifndef DIV
#define DIV

#include "../base.hpp"
#include "op.hpp"
#include "../visitor.hpp"

class Div: public Base
{
	protected:
		Base* left; 
		Base* right;
		double dividend, divisor, answer;
		std::string lString, rString, finalString;
	public:
		Div(Base* lh, Base* rh)
		{
			left = lh; right = rh;
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
		
		void accept(CountVisitor* v){
			v->div_count();
		}
};
#endif

