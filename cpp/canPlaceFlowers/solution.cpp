// https://leetcode.com/problems/can-place-flowers/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n)
	{
		return can_place(flowerbed, 0, n) || can_place(flowerbed, 1, n);
	}

private:
	bool can_place(const std::vector<int>& flowerbed, size_t i, int n)
	{
		if (n == 0)
			return true;
		if (i >= flowerbed.size())
			return false;

		int prev = (i - 1 >= flowerbed.size() ? 0 : flowerbed[i - 1]);
		int next = (i + 1 >= flowerbed.size() ? 0 : flowerbed[i + 1]);
		if (prev + next + flowerbed[i] == 0)
			--n;

		return can_place(flowerbed, i + 2, n);
	}
};

int main(int argc, char** argv)
{
}
