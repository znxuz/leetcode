// https://leetcode.com/problems/longest-palindrome/

package longestPalindrome;

import java.util.HashSet;
import java.util.Set;

class Solution {

    public int longestPalindrome(String s) {
		int[] alpha = new int[128];
		for (char c : s.toCharArray())
			alpha[c]++;
		int maxlen = 0;
		for (int count : alpha) 
			maxlen += count / 2 * 2;

		if (maxlen < s.length())
			maxlen++;
		return maxlen;
	}

    public int longestPalindromeSet(String s) {
		Set<Character> set = new HashSet<>();
		for (char c : s.toCharArray()) {
			if (set.contains(c))
				set.remove(c);
			else
				set.add(c);
		}

		int odd = set.size();
		return s.length() - (odd > 0 ? odd - 1 : 0);
    }
}
