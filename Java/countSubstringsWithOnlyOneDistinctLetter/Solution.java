// https://leetcode.com/problems/count-substrings-with-only-one-distinct-letter/

package countSubstringsWithOnlyOneDistinctLetter;

class Solution {

	// dynamic programming
	// time complexity: O(n)
	// space complexity: O(1): extra array unnecessary
	public int countLetters(String s) {
		int sum = 1;
		int count = 1;
		for (int i = 1; i < s.length(); ++i) {
			if (s.charAt(i) == s.charAt(i - 1))
				count++;
			else
				count = 1;
			sum += count;
		}

		return sum;
	}

	// time complexity: O(n)
	// space complexity: O(1)
    public int countLettersGauss(String s) {
		int sum = 0;
		int count = 0;
		char prev = 0;
		for (int i = 0; i < s.length(); ++i) {
			char cur = s.charAt(i);
			if (cur == prev) {
				count++;
			} else {
				prev = cur;
				sum += gauss(count);
				count = 1;
			}
		}
		sum += gauss(count);

		return sum;
    }

	private int gauss(int n) {
		return (n * (n + 1)) / 2;
	}

}
