#include "VectorContainer.hpp"
#include <iostream>

void VectorContainer::set_sort_function(Sort* func)
{
	this->sort_func = func;
}

void VectorContainer::add_element(Base* element)
{
	this->vContainer.push_back(element);
}

void VectorContainer::print()
{
	for(int i = 0; i < this->vContainer.size(); i++)
	{
		std::cout << vContainer[i]->stringify();
	}
}

void VectorContainer::sort()
{
	if(this->sort_func != nullptr)
	{
		this->sort_func->sort(this);
	}
}

void VectorContainer::swap(int i, int j)
{
	Base* tmp = this->vContainer[i];
	this->vContainer[i] = this->vContainer[j];
	this->vContainer[j] = tmp;
}

Base* VectorContainer::at(int i)
{
	return this->vContainer[i];
}

int VectorContainer::size()
{
	return this->vContainer.size();
}
