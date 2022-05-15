// https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/

#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    int countPrimeSetBits(int left, int right)
    {
	std::unordered_set<size_t> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
	int cnt = 0;
	for (int i = left; i <= right; ++i)
	    cnt += primes.count(bitset<32>(i).count());
	return cnt;
    }
};

int main(int argc, char** argv)
{
}
