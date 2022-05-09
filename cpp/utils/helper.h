#pragma once

#include <iostream>
#include <sstream>

namespace util
{
    template<typename iter> void iter_print(iter begin, iter end)
    {
	while (begin != end)
	    std:: cout << *begin++ << (begin == end ? "\n" : " ");
    }
};
