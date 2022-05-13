// https://leetcode.com/problems/find-anagram-mappings/

#include <stack>
#include <unordered_map>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2)
    {
	std::unordered_map<int, std::stack<int>> mp;
	for (size_t i = 0; i < nums2.size(); ++i)
	    mp[nums2[i]].push(i);

	std::vector<int> maps(nums1.size());
	for (size_t i = 0; i < maps.size(); ++i) {
	    auto& list = mp[nums1[i]];
	    maps[i] = list.top();
	    list.pop();
	}

	return maps;
    }
};

int main(int argc, char** argv)
{
}
