#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> map;
            for (int i = 0; i < nums.size(); ++i) {
                int diff = target - nums[i];
                if (map.count(diff))
                    return {map[diff], i};
                map[nums[i]] = i;
            }

            return {};
        }

        vector<int> twoSumBruteForce(vector<int>& nums, int target) {
            for (int i = 0; i < nums.size(); ++i) {
                for (int j = i + 1; j < nums.size(); ++j)
                    if (nums[i] + nums[j] == target)
                        return vector<int>{i, j};
            }
            return vector<int>{};
        }
};
