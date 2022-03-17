// https://leetcode.com/problems/happy-number/

#include <cmath>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;

class Solution
{
	public:
		bool isHappy(int n)
		{
			int slow = cross_square_sum(n);
			if (slow == 1)
				return true;
			int fast = cross_square_sum(slow);
			while (slow != fast) {
				if (fast == 1 || slow == 1)
					return true;
				slow = cross_square_sum(slow);
				fast = cross_square_sum(cross_square_sum(fast));
			}

			return false;
		}

	private:
		int cross_square_sum(int n)
		{
			if (n == 0)
				return std::pow(n, 2);
			return std::pow(n % 10, 2) + cross_square_sum(n / 10);
		}
};

int main(int argc, char** argv)
{
}
