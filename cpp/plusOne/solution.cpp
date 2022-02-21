// https://leetcode.com/problems/plus-one/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
		vector<int> plusOne(vector<int>& digits)
		{
			int carry = 1;
			for (int i = digits.size() - 1; i >= 0 && carry; --i) {
				digits[i] = ++digits[i] % 10;
				carry = (digits[i] == 0);
			}

			if (carry)
				digits.insert(digits.begin(), 1);
			return digits;
		}
};

int main(int argc, char** argv)
{
}
