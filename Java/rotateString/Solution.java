// https://leetcode.com/problems/rotate-string/

package rotateString;

// constraints given:
// 		1 <= s.length, goal.length <= 100
// 		s, goal consists of english lowercase letters
class Solution {

	// KMP, double match string algorithm, ...
	// time complexity: O(n^2)
	// space complexity: O(1)
    public boolean rotateString(String s, String goal) {
		int sLen = s.length();
		int goalLen = goal.length();
		if(sLen != goalLen)
			return false;

		for (int i = 0; i < sLen; i++) {
			int idx = 0;
			while (idx < goalLen) {
				if (s.charAt(idx) != goal.charAt((idx + i) % goalLen))
					break;
				idx++;
			}
			if (idx == goalLen)
				return true;
		}

		return false;
    }

	public boolean rotateStringOneLine(String s, String goal) {
		return s.length() == goal.length() && (s + s).contains(goal);
	}
}
