#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() {}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &obj) : tree_bag(obj)
{}

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &obj)
{
	if(this != &obj)
		tree_bag::operator=(obj);
	return *this;
}

searchable_tree_bag::~searchable_tree_bag()
{}

bool searchable_tree_bag::has(int val) const
{
    node *n = tree;
    while (n)
    {
        if (n->value == val)
            return true;
        if (n->value > val)
            n = n->l;
        else
            n = n->r;
    }
    return false;
}
//** */