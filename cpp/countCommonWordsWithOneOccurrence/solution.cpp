// https://leetcode.com/problems/count-common-words-with-one-occurrence/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
	public:
		// time complexity: O(n + m)
		// space complexity: O(n + m)
		int countWords(vector<string>& words1, vector<string>& words2)
		{
			unordered_map<string, int> freq;
			for (auto& s : words1)
				freq[s]++;
			for (auto& s : words2) {
				if (freq[s] == 1)
					freq[s]--;
				else
					freq[s] = -1;
			}

			int cnt = 0;
			for (const auto& p : freq)
				if (p.second == 0)
					cnt++;
			return cnt;
		}
};

int main(int argc, char** argv)
{
}
