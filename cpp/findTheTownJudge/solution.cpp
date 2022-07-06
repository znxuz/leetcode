// https://leetcode.com/problems/find-the-town-judge/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
	auto votes = std::vector<int>(static_cast<size_t>(n));
	for (const auto& vote : trust) {
	    votes[vote.front() - 1] = std::numeric_limits<int>::min();
	    ++votes[vote.back() - 1];
	}

	for (auto i = 0ul; i < votes.size(); ++i)
	    if (votes[i] == n - 1 && votes[i] >= 0)
		return i + 1;
	return -1;
    }
};

int main(int argc, char** argv)
{
}
