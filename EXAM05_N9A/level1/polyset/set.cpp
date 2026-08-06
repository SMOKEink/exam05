#include "set.hpp"

set::set() : bag(0) {}

set::set(searchable_bag &bag) : bag(&bag) {}

set::set(const set &obj) : bag(obj.bag) {}

set &set::operator=(const set &obj)
{
    if (this != &obj)
        bag = obj.bag;
    return *this;
}

set::~set() {}

void set::insert(int val)
{
    if (!bag->has(val))
        bag->insert(val);
}
void set::insert(int *arr, int size)
{
    int i = 0;
    while (i < size)
    {
        if (!bag->has(arr[i]))
            bag->insert(arr[i]);
        i++;
    }
}
void set::print() const
{
    bag->print();
}
void set::clear()
{
    bag->clear();
}
searchable_bag& set::get_bag() const
{
    return (*bag);
}
bool set::has(int v) const
{
    return (bag->has(v));
}