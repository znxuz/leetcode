// https://leetcode.com/problems/mean-of-array-after-removing-some-elements/

#include <algorithm>
#include <numeric>

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    double trimMean(vector<int>& arr) 
    {
	return use_nth_elem(arr);
    }

private:
    double use_nth_elem(std::vector<int> &arr)
    {
	size_t margin = arr.size() / 20;
	std::nth_element(begin(arr), begin(arr) + margin, end(arr));
	std::nth_element(begin(arr) + margin, end(arr) - margin, end(arr));
	auto sum = std::accumulate(begin(arr) + margin, end(arr) - margin, 0.0);
	return sum / (arr.size() - margin * 2);
    }

    double sort(std::vector<int> &arr)
    {
	std::sort(begin(arr), end(arr));
	size_t margin = static_cast<size_t>(static_cast<double>(arr.size()) * 0.05);
	double sum = std::accumulate(begin(arr) + margin, end(arr) - margin, 0.0, std::plus<double>());
	return sum / (arr.size() - margin * 2);
    }
};

int main(int argc, char **argv)
{
}
