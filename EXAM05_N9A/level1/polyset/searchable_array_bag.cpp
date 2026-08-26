#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag() {}

searchable_array_bag::searchable_array_bag(const searchable_array_bag &obj) : array_bag(obj)
{}

searchable_array_bag &searchable_array_bag::operator=(const searchable_array_bag &obj)
{
    if(this != &obj)
        array_bag::operator=(obj);
    return *this;
}

searchable_array_bag::~searchable_array_bag() {}

bool searchable_array_bag::has(int val) const
{
    int i = 0;
    while (i < size)
    {
        if(data[i] == val)
            return true;
        i++;
    }
    return false;
}   
