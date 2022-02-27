// https://leetcode.com/problems/reverse-integer/

#include <cstdint>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
	public:
		// time: O(n)
		// space: O(1)
		int reverse(int x)
		{
			int res = 0;
			int tmp = x;
			while (tmp != 0) {
				int last = std::abs(tmp % 10);
				if (res > INT_MAX / 10 || (res == INT_MAX / 10 && last > 7))
					return 0;
				res = res * 10 + last;
				tmp /= 10;
			}

			return (x < 0) ? -res : res;
		}
};

int main(int argc, char** argv)
{
}
