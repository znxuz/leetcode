#include <iostream>
#include <sstream>

template<typename iter> void iter_print(iter begin, iter end)
{
	while (begin != end)
		std:: cout << *begin++ << (begin == end ? "\n" : " ");
}
