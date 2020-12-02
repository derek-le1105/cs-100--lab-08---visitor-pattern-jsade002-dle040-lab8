#include <iostream>


#include "base.hpp"
#include "operations/op.hpp"
#include "operations/Add.hpp"
#include "operations/Mult.hpp"
#include "operations/Sub.hpp"
#include "operations/div.hpp"
#include "operations/pow.hpp"
#include "Factory.hpp"


int main(int argv, char** argc) 
{
	Factory* factory = new Factory();
	Base* result = factory->parse(argc, argv);
	//std::cout << argc[1] << std::endl;	
	if(result == nullptr)
		std::cout << "invalid equation." << std::endl;

        else
			std::cout << "String form: " << result->stringify() << std::endl << "Answer: " << result->evaluate() << std::endl;
    return 0;
}
