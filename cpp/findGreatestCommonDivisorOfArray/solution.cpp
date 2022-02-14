// https://leetcode.com/problems/find-greatest-common-divisor-of-array/

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
        int findGCD(vector<int>& nums)
        {
            int min = INT32_MAX;
            int max = INT32_MIN;
            for (int n : nums) {
                min = std::min(min, n);
                max = std::max(max, n);
            }
            return gcd(min, max);
        }

        int gcd(int x, int y)
        {
            return y == 0 ? x : gcd(y, x % y);
        }
};

int main(int argc, char** argv)
{
}
