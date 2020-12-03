#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "../base.hpp"
#include "op.hpp"
#include "../visitor.hpp"

class Sub: public Base{
protected:
    Base* left; 
    Base* right;
    double lhs, rhs, minusAnswer;
    std::string lhsString, rhsString, minusString;
public:
    Sub(Base* lhsOp, Base* rhsOp){
        left = lhsOp; right = rhsOp;
        lhs = lhsOp->evaluate(); rhs = rhsOp->evaluate();
        lhsString = lhsOp->stringify(); rhsString = rhsOp->stringify();
    }

    virtual double evaluate() {
        minusAnswer = lhs - rhs;
        return minusAnswer;
    }
    virtual std::string stringify() {
        minusString = "(" + lhsString + " - " + rhsString + ")";
        return minusString;
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
	v->visit_sub();
    }

};

#endif //__SUB_HPP__
