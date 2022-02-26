// https://leetcode.com/problems/count-operations-to-obtain-zero/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
		// euclidean gcd
		// time: O(log(min(a, b)))
		// space: O(1)
		int countOperations(int a, int b)
		{
			int cnt = 0;
			while (std::min(a, b)) {
				if (a < b)
					std::swap(a, b);
				cnt += a / b;
				a = a % b;
			}

			return cnt;
		}

		int countOperationsBruteForce(int num1, int num2)
		{
			int cnt = 0;
			while (num1 > 0 && num2 > 0) {
				if (num1 >= num2)
					num1 -= num2;
				else
					num2 -= num1;
				cnt++;
			}

			return cnt;
		}
};

int main(int argc, char** argv)
{
}
