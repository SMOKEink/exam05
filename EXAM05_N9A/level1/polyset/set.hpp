#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"

class set
{
    private:
        searchable_bag *bag;
    public:
        set();
        set(const set& obj);
        set(searchable_bag& bag);
        set& operator=(const set& obj);
        ~set();

        void insert(int val);
        void insert(int *arr, int size);
        void print() const;
        void clear();

        searchable_bag& set::get_bag() const;
        bool has(int val) const;
};

#endif