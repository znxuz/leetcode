// https://leetcode.com/problems/longest-common-prefix/

package longestCommonPrefix;

class Solution {

	// n = length of array, m = length of string
	// time complexity: O(n * m)
	// space complexity: O(n * log_2(m))
	public String longestCommonPrefix(String[] strs) {
		if (strs == null)
			return "";
		return longestCommonPrefix(strs, 0, strs.length - 1);
	}

	private String longestCommonPrefix(String[] strs, int left, int right) {
		if (left == right)
			return strs[left];
		int mid = left + (right - left) / 2;
		String leftCommon = longestCommonPrefix(strs, left, mid);
		String rightCommon = longestCommonPrefix(strs, mid + 1, right);

		return commonPrefix(leftCommon, rightCommon);
	}

	private String commonPrefix(String s1, String s2) {
		if (s1 == null || s2 == null)
			return "";
		for (int i = 0; i < s1.length(); i++) {
			if (i >= s2.length() || s1.charAt(i) != s2.charAt(i))
				return s1.substring(0, i);
		}
		return s1;
	}

	// n = length of array, m = length of string
	// time complexity: O(n * m)
	// space complexity: O(1)
	public String longestCommonPrefixVerticalScan(String[] strs) {
		if (strs == null || strs[0] == null)
			return "";
		for (int i = 0; i < strs[0].length(); i++) {
			for (int j = 0; j < strs.length; j++) {
				if (strs[j] == null
						|| i >= strs[j].length()
						|| strs[j].charAt(i) != strs[0].charAt(i))
					return strs[0].substring(0, i);
			}
		}
		return strs[0];
	}
}
