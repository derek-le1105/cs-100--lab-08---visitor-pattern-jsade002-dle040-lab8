#include "bubble_sort.hpp"

void bubble_sort::sort(Container* container){
    int i, j, temp;
    int containerSize = container->size();

    for(i = 0; i < containerSize - 1; ++i){
        for(j = 0; j < containerSize - i - 1; ++j){
            if(container->at(j)->evaluate() > container->at(j + 1)->evaluate())
                container->swap(j, j+1);
        }   
    }
}
