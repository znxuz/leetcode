// https://leetcode.com/problems/group-anagrams/

#include <unordered_map>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;

class Solution
{
	public:
		vector<vector<string>> groupAnagrams(vector<string>& strs)
		{
			std::unordered_map<string, vector<string>> map;
			for (const auto& s : strs)
				map[str_sort(s)].push_back(s);

			std::vector<vector<string>> res;
			for (const auto& [key, val] : map)
				res.push_back(val);

			return res;
		}

	private:
		string str_sort(const string& s)
		{
			string res;
			res.resize(26);
			for (char c : s)
				++res[c - 'a'];
			// for (auto& c : res)
				// c += '0';

			return res;
		}
};

int main(int argc, char** argv)
{
}
