#include "set.hpp"

set::set(searchable_bag& bag) : _bag(bag) {}

set::set(const set& other) : _bag(other._bag) {}

set::~set() {}

set& set::operator=(const set& other) {
	if (this!= &other)
		*this = other;
	return *this;
}

void set::insert(int i) {
	if (!_bag.has(i))
		_bag.insert(i);
}

void set::insert(int *arr, int i) {
	if (!_bag.has(arr[i]))
		_bag.insert(arr[i]);
}

void set::print() const {
	_bag.print();
}

void set::clear() {
	_bag.clear();
}

bool set::has(int val) const{
	if (_bag.has(val))
		return true;
	else
		return false;
}

searchable_bag& set::get_bag() const {
	return _bag;
}
