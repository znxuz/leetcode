// https://leetcode.com/problems/teemo-attacking/

#include <ctime>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	int findPoisonedDuration(vector<int>& timeSeries, int duration)
	{
		int prev = -1;
		int cnt = 0;
		for (auto t : timeSeries) {
			if (prev != -1)
				cnt += std::min(duration, t - prev);
			prev = t;
		}

		return cnt + duration;
	}
};

int main(int argc, char** argv)
{
}
