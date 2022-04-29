// https://leetcode.com/problems/minimum-index-sum-of-two-lists/

#include <limits>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	// time: O(n + m)
	// space: O(n + m)
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
	{
		std::unordered_map<std::string, size_t> sum;
		std::unordered_set<std::string> uniques;

		for (size_t i = 0; i < list1.size(); ++i) {
			sum[list1[i]] += i;
			uniques.insert(list1[i]);
		}
		for (size_t i = 0; i < list2.size(); ++i) {
			if (uniques.erase(list2[i]))
				sum[list2[i]] += i;
		}

		std::vector<std::string> res;
		size_t min = std::numeric_limits<size_t>::max();
		for (const auto& [name, cnt] : sum) {
			if (uniques.count(name) || cnt > min)
				continue;
			if (cnt < min)
				res.clear();
			res.push_back(name);
			min = std::min(min, cnt);
		}

		return res;
	}
};

int main(int argc, char** argv)
{
}
