#include "list_container.hpp"

void listContainer::set_sort_function(Sort* sort_function){
    this->sort_function = sort_function;
}

void listContainer::add_element(Base* element){
    container.push_back(element);
}

void listContainer::print(){
    std::list<Base*>::iterator it = container.begin();
    int containerSize = container.size();
    std::string expression = "";
    for(it; it != container.end(); ++it){
        expression += container.front()->stringify();       
    }

    std::cout << expression;
}

void listContainer::sort(){
    sort_function->sort(this);
}

void listContainer::swap(int i , int j){
    Base* tmp;
    std::list<Base*>::iterator it1 = container.begin();
    std::list<Base*>::iterator it2 = container.begin();
    std::advance(it1, i);
    std::advance(it2, j);
    std::swap(*it1, *it2);       
}

Base* listContainer::at(int i){
    std::list<Base*> tempList = container;
    int count = 0;
    while(count != i){
        tempList.pop_front();
        ++count;
    }

    return tempList.front();
}

int listContainer::size(){
    return container.size();
}
