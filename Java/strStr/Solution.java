// https://leetcode.com/problems/implement-strstr/

package strStr;

class Solution {

	// KMP algorithm

	// time complexity: O(n^2)
	// spacecomplexity: O(1)
    public int strStr(String haystack, String needle) {
		for (int i = 0; ; i++) {
			for (int j = 0; ; j++) {
				if (haystack.charAt(i + j) != needle.charAt(j))
					break;
				if (j == needle.length())
					return i;
				if (i + j == haystack.length())
					return -1;
			}
		}
	}

	// time complexity: O(n^2)
	// spacecomplexity: O(1)
    public int strStrLoop(String haystack, String needle) {
		if (haystack == null || needle == null)
			return -1;
		if (needle.equals(""))
			return 0;

		int indexLimit = haystack.length() - needle.length();
		for (int i = 0; i < haystack.length() && i <= indexLimit; i++) {
			int needle_i = 0;
			while (needle_i < needle.length() && i + needle_i < haystack.length()
					&& haystack.charAt(i + needle_i) == needle.charAt(needle_i)) {
				needle_i++;
			}
			if (needle_i == needle.length())
				return i;
		}

		return -1;
    }
}
