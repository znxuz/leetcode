// https://leetcode.com/problems/reverse-string-ii/

package reverseStringII;

class Solution {

	// time complexity: O(n)
	// space complexity: O(n)
    public String reverseStr(String s, int k) {
		var stringBuilder = new StringBuilder();
		int len = s.length();
		for (int i = 0; i < len; i += k * 2) {
			int limit = Math.min(i + k, len);
			for (int j = limit - 1; j >= i; j--) {
				stringBuilder.append(s.charAt(j));
			}
			for (int j = limit; j < i + k * 2 && j < len; j++) {
				stringBuilder.append(s.charAt(j));
			}
		}

		return stringBuilder.toString();
    }
}
