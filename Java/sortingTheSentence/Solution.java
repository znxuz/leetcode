// https://leetcode.com/problems/sorting-the-sentence/

package sortingTheSentence;

import java.util.Arrays;

class Solution {

	// time complexity: O(n)
	// space complexity: O(n)
    public String sortSentence(String s) {
		int[] order = new int[9];
		int len = 0;
		for (int i = 0, idx = 0; i < s.length(); ++i) {
			if (i == s.length() - 1 || s.charAt(i + 1) == ' ') {
				order[s.charAt(i) - '0' - 1] = idx;
				idx = i + 2;
				len++;
			}
		}

		var strBuilder = new StringBuilder();
		for (int i = 0; i < len; ++i) {
			int end = order[i] + 1;
			while (end < s.length() && s.charAt(end) != ' ')
				end++;
			strBuilder.append(s.substring(order[i], end - 1));
			if (i < len - 1)
				strBuilder.append(' ');
		}

		return strBuilder.toString();
	}

	// time complexity: O(n logn)
	// space complexity: O(n)
    public String sortSentenceSort(String s) {
		String[] arr = s.split("\\s");
		Arrays.sort(arr, (s1, s2)
				-> Integer.compare(s1.charAt(s1.length() - 1), s2.charAt(s2.length() - 1)));
		var strBuilder = new StringBuilder();
		for (int i = 0; i < arr.length; ++i) {
			strBuilder.append(arr[i].substring(0, arr[i].length() - 1));
			if (i != arr.length - 1)
				strBuilder.append(" ");
		}

		return strBuilder.toString();
    }
}
