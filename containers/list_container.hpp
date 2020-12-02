#ifndef __LIST_CONTAINER_HPP__
#define __LIST_CONTAINER_HPP__

#include "../container.hpp"
#include "../sort.hpp"
#include "../base.hpp"
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include <utility>
#include <iostream>

class Sort;
class Base;

class listContainer : public Container{
    protected:
        std::list<Base*> container;
        Sort* sort_function;
    public:
        listContainer(): sort_function(nullptr) {};
        listContainer(Sort* function): sort_function(function) {};

        void set_sort_function(Sort* sort_function);

        virtual void add_element(Base* element);
       
        virtual void print();
       
        virtual void sort();
       
        virtual void swap(int i, int j);
        
        virtual Base* at(int i);
        
        virtual int size();
};

#endif //__LIST_CONTAINER_HPP__
