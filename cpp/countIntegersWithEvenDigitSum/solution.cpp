// https://leetcode.com/problems/count-integers-with-even-digit-sum/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
		// time: O(n)
		// space: O(1)
		int countEven(int num)
		{
			int sum = 0;
			for (int i = num; i > 0; i /= 10)
				sum += i % 10;
			return (num - sum % 2) / 2;
		}
	
		// time: O(n^2)
		// space: O(1)
		int countEvenBruteForce(int num)
		{
			int cnt = 0;
			for (int i = 2; i <= num; ++i) {
				int sum = 0;
				int n = i;
				while (n > 0) {
					sum += n % 10;
					n /= 10;
				}
				if (!(sum & 1))
					cnt++;
			}

			return cnt;
		}
};

int main(int argc, char** argv)
{
}
