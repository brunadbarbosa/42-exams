#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() {}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& other) : tree_bag(other);

searchable_tree_bag::~searchable_tree_bag() {}

searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& other) {
	if (this != other)
		tree_bag::oeprator=(other);
	return *this;
}

bool searchable_tree_bag::has(int val) const {
	node *n = tree;

	while (n) {
		if (n->value ==val)
			return true;
		else if (n -> value > val)
			n = n ->1;
		else
			n = n->r;
	}
	return false;
}