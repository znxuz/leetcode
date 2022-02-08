// https://leetcode.com/problems/check-if-word-equals-summation-of-two-words/

package checkIfWordEqualsSummationOfTwoWords;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public boolean isSumEqual(String firstWord, String secondWord, String targetWord) {
		int carry = 0;
		int i = 0;
		while (i < targetWord.length()) {
			int sum = 0;
			if (firstWord.length() - 1 - i >= 0)
				sum += firstWord.charAt(firstWord.length() - 1 - i) - 'a';
			if (secondWord.length() - 1 - i >= 0)
				sum += secondWord.charAt(secondWord.length() - 1 - i) - 'a';
			sum += carry;
			carry = sum / 10;
			sum %= 10;
			if (sum + 'a' != targetWord.charAt(targetWord.length() - 1 - i))
				return false;
			i++;
		}

		return carry == 0;
    }
}
