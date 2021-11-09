// https://leetcode.com/problems/student-attendance-record-i

package studentAttendanceRecordI;

class Solution {

    public boolean checkRecord(String s) {
		return !s.matches(".*(A.*A|L{3,}).*");
	}

    public boolean checkRecordLinear(String s) {
		int ctrA, ctrL;
		ctrA = ctrL = 0;
		for (char c : s.toCharArray()) {
			if (c == 'A')
				ctrA++;
			if (c == 'L')
				ctrL++;
			else
				ctrL = 0;
			if (ctrA == 2 || ctrL == 3)
				return false;
		}

		return true;
    }
}
