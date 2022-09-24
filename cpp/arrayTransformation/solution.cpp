// https://leetcode.com/problems/array-transformation/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    vector<int> transformArray(vector<int>& arr) 
    {
	return optimal_space(arr);
    }

private:
    // time: O(n^2)
    // space: O(1)
    std::vector<int> optimal_space(std::vector<int>& arr)
    {
	if (arr.size() < 3)
	    return arr;

	auto n = arr.size();
	bool loop;
	int prev, next;
	do {
	    loop = false;
	    prev = arr.front();
	    for (auto i = 1ul; i < n - 1; ++i) {
		auto tmp = arr[i];
		next = arr[i + 1];
		if (tmp < prev && tmp < next)
		    ++arr[i], loop = true;
		else if (tmp > prev && tmp > next)
		    --arr[i], loop = true;
		prev = tmp;
	    }
	} while (loop);

	return arr;
    }

    // time: O(n^2)
    // space: O(n)
    std::vector<int> extra_space(std::vector<int>& arr)
    {
	auto n = arr.size();
	auto cp = std::vector<int>(n);
	auto loop = false;
	do {
	    std::copy(begin(arr), end(arr), begin(cp));
	    loop = false;
	    for (auto i = 1ul; n > 2 && i < n - 1; ++i) {
		if (cp[i] < arr[i - 1] && cp[i] < arr[i + 1])
		    ++cp[i], loop = true;
		else if (cp[i] > arr[i - 1] && cp[i] > arr[i + 1])
		    --cp[i], loop = true;
	    }
	    if (loop)
		std::copy(begin(cp), end(cp), begin(arr));
	} while (loop);

	return cp;
    }
};

int main(int argc, char **argv)
{
}
