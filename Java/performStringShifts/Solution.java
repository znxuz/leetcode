// https://leetcode.com/problems/perform-string-shifts/

package performStringShifts;

class Solution {

	// calc total shifts and set the begin index to compose the shifted string
	// time complexity: O(n)
	// space complexity: O(n)
    public String stringShift(String s, int[][] matrix) {
		int shifts = 0;
		for (var m : matrix) {
			shifts = (shifts + (m[0] == 0 ? -m[1] : m[1])) % s.length();
		}
		var stringBuilder = new StringBuilder();
		int begin = ((shifts > 0) ? s.length() : 0) - shifts;
		for (int i = 0; i < s.length(); ++i) {
			stringBuilder.append(s.charAt(begin));
			begin = (begin + 1) % s.length();
		}

		return stringBuilder.toString();
    }
}
