#include <vector>
#include <iostream>

template<typename T> void print_vector(const std::vector<T>& vec)
{
	for (std::size_t i = 0; i < vec.size(); ++i)
		std::cout << vec.at(i) << ((i + 1 == vec.size()) ? "" : " ");
	std::cout << '\n';
}
