// https://leetcode.com/problems/duplicate-zeros/

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
	two_passes(arr);
    }

private:
    void one_pass(std::vector<int> &arr)
    {
    }

    void two_asses(std::vector<int> &arr)
    {
	auto shift = 0u;
	for (auto n : arr)
	    if (!n)
		++shift;

	for (auto i = arr.size() - 1; i < arr.size(); --i) {
	    if (!arr[i])
		--shift;
	    if (i + shift < arr.size())
		arr[i + shift] = arr[i];
	    if (!arr[i] && i + shift + 1 < arr.size())
		arr[i + shift + 1] = 0;
	}
    }
};

template<typename ...types>
void test(types &&...args)
{
    Solution().duplicateZeros(std::forward<types&&>(args)...);
}

int main(int argc, char **argv)
{
    auto vec1 = std::vector<int>{1,0,2,3,0,4,5,0};
    print_container(vec1);
    Solution().duplicateZeros(vec1);
    print_container(vec1);
}
