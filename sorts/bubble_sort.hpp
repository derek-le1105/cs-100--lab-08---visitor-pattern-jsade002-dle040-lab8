#ifndef __BUBBLE_SORT_HPP__
#define __BUBBLE_SORT_HPP__

#include "../container.hpp"

class Container;

class bubble_sort : public Sort{
        public:
	bubble_sort(){};
        virtual void sort(Container* container);
};

#endif
