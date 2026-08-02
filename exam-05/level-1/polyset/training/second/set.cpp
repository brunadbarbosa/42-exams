#include "set.hpp"

set::set(searchable_bag& _bag) : _bag(bag) {}

set::set(const set& other) : _bag(other._bag) {}

set::~set();

set& set::operator=(const set& other) {
	if (this!= &other)
		*this = other;
	return *this;
}

void set::insert(int val) {
	if (!_bag.has(val))
		_bag.insert(val);
}

void set::insert(int *arr, int size) {
	for (int i = 0; i < size; i++)
	{
		if (!_bag.has(arr[i]))
			_bag.insert(arr[i]);
	}
}

void set::print() const {
	_bag.print();
}

void set::clear() {
	_bag.clear();
}

bool set::has(int val) const {
	return _bag.has(val);
}

const searchable_bag& set::get_bag() const {
	return _bag;
}
