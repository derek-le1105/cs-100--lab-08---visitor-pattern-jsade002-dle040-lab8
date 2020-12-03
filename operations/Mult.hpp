#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "../base.hpp"
#include "op.hpp"
#include "../visitor.hpp"

class Mult: public Base{
protected:
    Base* left;
    Base* right;
    double lhs, rhs, multAnswer;
    std::string lhsString, rhsString, multString;
public:
    Mult(Base* lhsOp, Base* rhsOp){
        left = lhsOp; right = rhsOp;
        lhs = lhsOp->evaluate(); rhs = rhsOp->evaluate();
        lhsString = lhsOp->stringify(); rhsString = rhsOp->stringify();
    }

    virtual double evaluate() {
        multAnswer = lhs * rhs;
        return multAnswer;
    }
    virtual std::string stringify() {
        multString = "(" + lhsString + " * " + rhsString + ")";
        return multString;
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
	v->visit_mult();
    }

};


#endif //__MULT_HPP__
