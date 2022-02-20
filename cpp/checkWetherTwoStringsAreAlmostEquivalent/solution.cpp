// https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/submissions/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
		bool checkAlmostEquivalent(string word1, string word2)
		{
			vector<int> cnts(26);
			for (int i = 0; i < word1.size(); ++i) {
				cnts[word1[i] - 'a']++;
				cnts[word2[i] - 'a']--;
			}

			for (int i = 0; i < cnts.size(); ++i)
				if (cnts[i] < -3 || cnts[i] > 3)
					return false;
			return true;
		}
};

int main(int argc, char** argv)
{
}
