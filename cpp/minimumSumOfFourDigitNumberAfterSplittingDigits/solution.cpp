// https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
		int minimumSum(int num)
		{
			int digits[10] = {0};
			while (num > 0) {
				digits[num % 10]++;
				num /= 10;
			}

			int sum = 0;
			int cnt = 0;
			for (int i = 0; i < 10; ++i) {
				while (digits[i]-- > 0)
					sum += (cnt++ < 2) ? i * 10 : i;
			}

			return sum;
		}
};

int main(int argc, char** argv)
{
}
