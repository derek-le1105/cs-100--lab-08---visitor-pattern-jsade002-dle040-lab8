#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "../base.hpp"
#include "op.hpp"
#include "../visitor.hpp"

class Add: public Base{
protected:
    double lhs, rhs, addAnswer;
    Base* left;
    Base* right;
    std::string lhsString, rhsString, addString;
public:
    Add(Base* lhsOp, Base* rhsOp){
        left = lhsOp; right = rhsOp;
        lhs = lhsOp->evaluate(); rhs = rhsOp->evaluate();
        lhsString = lhsOp->stringify(); rhsString = rhsOp->stringify();
    }

    virtual double evaluate() {
        addAnswer = lhs + rhs;
        return addAnswer;
    }
    virtual std::string stringify() {
        addString = "(" + lhsString + " + " + rhsString + ")";
        return addString;
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
	v->visit_add();
    }

};

#endif //__ADD_HPP__
