// https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
		// time: O(n * m)
		// space: O(1)
		int mostWordsFound(vector<string>& sentences)
		{
			int max = 0;
			for (auto& s : sentences) {
				// int cnt = count_if(s.begin(), s.end(), [](const auto& c) { return c == ' '; });
				int cnt = std::count(s.begin(), s.end(), ' ');
				max = std::max(max, cnt);
			}
			return max + 1;
		}
};

int main(int argc, char** argv)
{
}
