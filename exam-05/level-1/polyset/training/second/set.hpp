#pragma once

#include "subject/searchable_bag.hpp"

class set {
	private:
		searchable_bag& _bag;
	public:
		set(searchable_bag& bag);
		set(const set& other);
		~set();
		set& operator=(const set& other);

		void insert(int);
		void insert(int *, int);
		void print() const;
		void clear();
		bool has(int) const;

		const searchable_bag& get_bag() const;
}