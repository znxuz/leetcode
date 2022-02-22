// https://leetcode.com/problems/finding-3-digit-even-numbers/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
		// time: O(n) + O(10^3) = O(n)
		// space: O(n)
		vector<int> findEvenNumbers(vector<int>& digits)
		{
			int freq[10] = {0};
			for (int n : digits)
				freq[n]++;

			vector<int> res;
			for (int i = 1; i < 10; ++i) {
				if (freq[i] == 0)
					continue;
				int first = i;
				freq[i]--;
				for (int j = 0; j < 10; ++j) {
					if (freq[j] == 0)
						continue;
					int second = first * 10 + j;
					freq[j]--;
					for (int k = 0; k < 9; k += 2) {
						if (freq[k] == 0)
							continue;
						int third = second * 10 + k;
						res.push_back(third);
					}
					freq[j]++;
				}
				freq[i]++;
			}

			return res;
		}
};

int main(int argc, char** argv)
{
}
