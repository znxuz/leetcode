// https://leetcode.com/problems/meeting-rooms/

package meetingRooms;

import java.util.Arrays;

class Solution {

	// time complexity: O(n*log(n))
	// space complexity: O(1)
    public boolean canAttendMeetingsSort(int[][] intervals) {
		Arrays.sort(intervals, (i1, i2) -> Integer.compare(i1[0], i2[0]));

		int prev = 0;
		for (var interval : intervals) {
			for (int timestamp : interval) {
				if (timestamp < prev)
					return false;
				prev = timestamp;
			}
		}

		return true;
    }
}
