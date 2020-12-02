#ifndef __VECTORCONTAINER_HPP__
#define __VECTORCONTAINER_HPP__

#include <vector>
#include "../container.hpp"
#include "../sorts/SelectionSort.hpp"

class Sort;
class Base;

class VectorContainer : public Container
{
	protected:
		Sort* sort_func;
		std::vector<Base*> vContainer;
		
	public:
		VectorContainer() : sort_func(nullptr){};
		VectorContainer(Sort* func) : sort_func(func){};
		
		void set_sort_function(Sort* func);
		
		virtual void add_element(Base* element);
		virtual void print();
		virtual void sort();
		
		virtual void swap(int i, int j);
		virtual Base* at(int i);
		virtual int size();
};

#endif
