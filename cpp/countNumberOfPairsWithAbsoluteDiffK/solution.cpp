#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
    public:
        // time complexity: O(n)
        // space complexity: O(1)
        int countKDifference(vector<int>& nums, int k)
        {
            vector<int> cnts(101);
            for (int n : nums)
                cnts[n]++;

            int cnt = 0;
            for (int i = k; i < cnts.size(); ++i) {
                cnt += cnts[i] * cnts[i - k];
            }
            return cnt;
        }

        // time complexity: O(n)
        // space complexity: O(n)
        int countKDifferenceMap(vector<int>& nums, int k)
        {
            unordered_map<int, int> map;
            for (int n : nums) {
                map[n] = (map.count(n) ? map[n] : 0) + 1;
            }

            int cnt = 0;
            for (std::pair<int, int> pair : map) {
                cnt += pair.second * (map.count(pair.first + k) ? map[pair.first + k] : 0);
            }
            return cnt;
        }
};

int main(int argc, char** argv)
{
}
