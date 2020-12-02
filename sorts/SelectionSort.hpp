#ifndef __SELECTIONSORT_HPP__
#define __SELECTIONSORT_HPP__

#include "../container.hpp"

class Container;

class SelectionSort : public Sort
{
	public:
	
		
		virtual void sort(Container* container);
};

#endif
