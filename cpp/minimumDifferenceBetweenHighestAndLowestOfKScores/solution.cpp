// https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/submissions/

#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    public:
        int minimumDifference(vector<int>& nums, int k)
        {
            std::sort(nums.begin(), nums.end());
            int min = INT32_MAX;
            for (int i = k - 1; i < nums.size(); ++i)
                min = std::min(min, nums[i] - nums[i - k + 1]);

            return min;
        }
};

int main(int argc, char** argv)
{
}
