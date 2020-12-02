#ifndef RAND
#define RAND

#include "../base.hpp"
#include "op.hpp"
#include <cstdlib>

class Rand : public Base
{
	protected:
		double value;
		std::string randString;
	public:
		Rand() : Base() { value = rand() % 100;}
		
		virtual double evaluate() { return value; }
		
		virtual std::string stringify()
		{
			randString = std::to_string(value);
			return randString;
		}
};

#endif
