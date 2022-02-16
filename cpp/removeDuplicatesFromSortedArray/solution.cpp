#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
		// time complexity: O(n)
		// space complexity: O(1)
		int removeDuplicates(vector<int>& nums)
		{
			int i = 0;
			int j = 0;
			while (j < nums.size()) {
				if (nums[j] == nums[i])
					j++;
				else {
					nums[i + 1] = nums[j];
					i++;
				}
			}
			return i + 1;
		}
};

int main(int argc, char** argv)
{
}
