// https://leetcode.com/problems/maximum-number-of-balloons/

package maximumNumberOfBallons;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public int maxNumberOfAnything(String text, String dest) {
		int[] destChars = new int[26];
		int[] ctr = new int[26];
		for (char c : dest.toCharArray())
			destChars[c - 'a']++;
		for (char c : text.toCharArray())
			ctr[c - 'a']++;

		int min = ctr[dest.charAt(0) - 'a'];
		for (char c : dest.toCharArray()) {
			if (destChars[c - 'a'] == 0)
				continue;
			min = Math.min(min, ctr[c - 'a'] / destChars[c - 'a']);
			destChars[c - 'a'] = 0;
		}

		return min;
	}

    public int maxNumberOfBalloonsSimple(String text) {
		int[] ctr = new int[26];
		for (char c : text.toCharArray())
			ctr[c - 'a']++;
		int min = ctr['b' - 'a'];
		for (char c : "balon".toCharArray()) {
			if (c == 'l' || c == 'o')
				ctr[c - 'a'] /= 2;
			min = Math.min(min, ctr[c - 'a']);
		}

		return min;
	}

    public int maxNumberOfBalloons(String text) {
		return maxNumberOfAnything(text, "balloon");
    }
}
