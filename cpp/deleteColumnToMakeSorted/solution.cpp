// https://leetcode.com/problems/delete-columns-to-make-sorted/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    int minDeletionSize(std::vector<std::string>& strs) 
    {
	auto cnt = 0ul;
	for (size_t i = 0; i < strs.front().size(); ++i) 
	{
	    bool is_sorted = false;
	    for (size_t j = 1; j < strs.size() && !is_sorted; ++j)
		if (strs[j][i] < strs[j - 1][i])
		    is_sorted = true;
	    cnt += is_sorted;
	}
	return cnt;
    }
};

int main(int argc, char** argv)
{
}
