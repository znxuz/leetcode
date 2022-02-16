#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
		// time complexity: O(n)
		// space complexity: O(1)
		int removeElement(vector<int>& nums, int val)
		{
			int i = 0;
			int j = 0;
			while (j < nums.size()) {
				if (nums[j] != val) {
					nums[i] = nums[j];
					i++;
				}
				j++;
			}
			return i;
		}
};

int main(int argc, char** argv)
{
}
