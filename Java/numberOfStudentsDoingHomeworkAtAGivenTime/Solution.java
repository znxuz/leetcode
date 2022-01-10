// https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/

package numberOfStudentsDoingHomeworkAtAGivenTime;

class Solution {

    public int busyStudent(int[] startTime, int[] endTime, int queryTime) {
		int ctr = 0;
		for (int i = 0; i < startTime.length; ++i) {
			if (queryTime >= startTime[i] && queryTime <= endTime[i])
				ctr++;
		}

		return ctr;
    }
}
