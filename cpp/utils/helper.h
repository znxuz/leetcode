#pragma once

#include <array>
#include <unordered_set>
#include <unordered_map>
#include <limits>
#include <vector>
#include <iostream>

namespace util
{
    template<typename container> void print_container(const container& c)
    {
	auto b = begin(c);
	auto e = end(c);
	while (b != e)
	    std:: cout << *b++ << (b == e ? "\n" : " ");
    }
};
