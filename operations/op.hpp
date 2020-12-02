#ifndef __OP_HPP__
#define __OP_HPP__

#include "../base.hpp"

class Op : public Base {
    protected:
	double inputValue;
	std::string opString;

    public:
	Op() : Base(){inputValue = 0.0; opString = "";}
        Op(double value) : Base(), inputValue(value) {}
        virtual double evaluate() { return inputValue; }
        virtual std::string stringify() {
	    opString = std::to_string(inputValue);
	    return opString;
	}
};

#endif //__OP_HPP__
