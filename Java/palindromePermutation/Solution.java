// https://leetcode.com/problems/palindrome-permutation/

package palindromePermutation;

import java.util.HashMap;
import java.util.Map;

class Solution {

	// 'voting' algorithm?
	// time complexity: O(n)
	// space complexity: O(1)
    public boolean canPermutePalindrome(String s) {
		char[] ascii = new char[256];
		int count = 0;
		for (char c : s.toCharArray()) {
			ascii[(int)c]++;
			if (ascii[(int)c] % 2 == 0)
				count--;
			else
				count++;
		}

		return count <= 1;
	}

	// time complexity: O(n) + stream operation
	// space complexity: O(n)
    public boolean canPermutePalindromeStream(String s) {
		Map<Character, Integer> map = new HashMap<>();
		for (char c : s.toCharArray()) {
			map.put(c, map.getOrDefault(c, 0) + 1);
		}

		return map.values().stream().filter(x -> x != 2).count() <= 1;
    }
}
