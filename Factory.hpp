#ifndef __FACTORY_HPP__
#define	__FACTORY_HPP__

#include "base.hpp"
#include "operations/op.hpp"
#include "operations/Add.hpp"
#include "operations/Sub.hpp"
#include "operations/Mult.hpp"
#include "operations/div.hpp"
#include "operations/pow.hpp"
#include <queue>
#include <iostream>


class Base;

class Factory {
public:
    Factory(){}
    Base* parse(char** input, int length){
	std::queue<char*> num;
	std::queue<char*> opr;
	std::string tmp;
	for(int i = 1; i < length; ++i){
		tmp = input[i];
		if(std::isdigit(tmp[0]))
			num.push(input[i]);
		else if(tmp == "+" || tmp == "-" || tmp == "/" || tmp == "\*" || tmp == "\*\*")
			opr.push(input[i]);
		else
			return nullptr;
	}
	if(opr.size() + 1 != num.size())
		return nullptr;
	num.push("0"); //buffer
	std::queue<Base*> calculate;
	Base* left;
	Base* right;
	Base* result;
	Base* tmp1;
	do{
		if(calculate.size() == 2){
		    left = calculate.front();
	    	    calculate.pop();
	       	    right = calculate.front();
		    calculate.pop();
	            tmp = opr.front();
		    if(tmp == "+"){
			result = new Add(left, right);
			calculate.push(result);
			opr.pop();
		    }
		    else if(tmp ==  "-"){
			result = new Sub(left, right);
			calculate.push(result);
			opr.pop();
		    }
		    else if(tmp ==  "/"){
			result = new Div(left, right);
			calculate.push(result);
			opr.pop();
		    }
		    else if(tmp == "\*"){
			result = new Mult(left, right);
			calculate.push(result);
			opr.pop();
		    }
		    else if(tmp == "\*\*"){
			result = new Pow(left, right);
			calculate.push(result);
			opr.pop();
		    }	
		}
	    tmp1 = new Op(std::stod(num.front()));
	    num.pop();
	    calculate.push(tmp1);
	}while(!num.empty());
	return calculate.front();
}
};

#endif
