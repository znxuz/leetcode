// https://leetcode.com/problems/meeting-rooms/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	bool canAttendMeetings(vector<vector<int>>& intervals)
	{
		return sort(intervals);
	}

private:
	// time: O(n * log(n))
	// space: O(n)
	bool sort(vector<vector<int>>& intervals)
	{
		std::sort(begin(intervals), end(intervals));
		for (size_t i = 1; i < intervals.size(); ++i) {
			if (intervals[i][0] < intervals[i - 1][1])
				return false;
		}

		return true;
	}
};

int main(int argc, char** argv)
{
}
