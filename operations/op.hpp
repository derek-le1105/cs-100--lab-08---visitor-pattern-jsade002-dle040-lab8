#ifndef __OP_HPP__
#define __OP_HPP__

#include "../base.hpp"
#include "../visitor.hpp"

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
	virtual Iterator* create_iterator(){
        Iterator* test = new NullIterator(this);
        return test;
    }

	virtual Base* get_left(){
        return nullptr;
    }

    virtual Base* get_right(){
        return nullptr;
    }

    void accept(CountVisitor* v){
	v->visit_op();
    }
};

#endif //__OP_HPP__
