// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
	public:
		// faster sliding window
		// time: O(n)
		// space: O(1)
		int lengthOfLongestSubstring(string s)
		{
			std::vector<int> flags(256, -1);
			int start = -1;
			int max = 0;
			for (int end = 0; end < s.length(); ++end) {
				if (flags[s[end]] > start)
					start = flags[s[end]];
				flags[s[end]] = end;
				max = std::max(max, end - start);
			}

			return max;
		}

		// sliding window
		// time: O(n)
		// space: O(n)
		int lengthOfLongestSubstringMap(string s)
		{
			unordered_map<char, int> map;
			int start = 0;
			int end = 0;
			int max = -1;
			while (end < s.size()) {
				if (map.count(s[end])) {
					max = std::max(max, end - start);
					int prev = map[s[end]];
					while (start <= prev)
						map.erase(s[start++]);
				}
				map[s[end]] = end;
				end++;
			}

			return std::max(max, end - start);
		}
};

int main(int argc, char** argv)
{
}
