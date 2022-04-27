// https://leetcode.com/problems/distribute-candies/

#include <unordered_set>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	int distributeCandies(vector<int>& types)
	{
		return std::min(std::unordered_set<int>(begin(types), end(types)).size(), types.size() / 2);
	}
};

int main(int argc, char** argv)
{
}
