// https://leetcode.com/problems/kth-distinct-string-in-an-array/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
	public:
		string kthDistinct(vector<string>& arr, int k)
		{
			unordered_map<string, int> freq;
			for (auto& s : arr)
				freq[s]++;
			for (auto& s : arr) {
				if (freq[s] == 1 && --k == 0)
					return s;
			}
			return "";
		}
};

int main(int argc, char** argv)
{
}
