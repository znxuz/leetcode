// https://leetcode.com/problems/find-the-middle-index-in-array/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
    public:
        // time complexity: O(2n)
        // space complexity: O(1)
        int findMiddleIndex(vector<int>& nums)
        {
            int sum = 0;
            for (auto n : nums)
                sum += n;

            int left = 0;
            for (int i = 0; i < nums.size(); ++i) {
                sum -= nums[i];
                if (left == sum)
                    return i;
                left += nums[i];
            }

            return -1;
        }

        // time complexity: O(n)
        // space complexity: O(n)
        int findMiddleIndexOnePass(vector<int>& nums)
        {
            unordered_map<int, int> map;
            int sum = 0;
            for (int i = 0; i < nums.size(); ++i) {
                int total = 2 * sum + nums[i];
                if (!map.count(total))
                    map[total] = i;
                sum += nums[i];
            }

            return map.count(sum) ? map[sum] : -1;
        }
};

int main(int argc, char** argv)
{
}
