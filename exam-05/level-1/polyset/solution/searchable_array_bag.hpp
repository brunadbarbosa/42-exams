#pragma once

#include "subject/searchable_bag.hpp"
#include "subject/array_bag.hpp"


class searchable_array_bag : public searchable_bag, public array_bag {
	public:
		searchable_array_bag();
		searchable_array_bag(const searchable_array_bag& other);
		~searchable_array_bag();
		searchable_array_bag& operator=(const searchable_array_bag& other);
		bool has(int) const;
}