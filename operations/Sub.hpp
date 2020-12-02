#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "../base.hpp"
#include "op.hpp"

class Sub: public Base{
protected:
    double lhs, rhs, minusAnswer;
    std::string lhsString, rhsString, minusString;
public:
    Sub(Base* lhsOp, Base* rhsOp){
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

};

#endif //__SUB_HPP__
