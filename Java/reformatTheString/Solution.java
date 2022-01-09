// https://leetcode.com/problems/reformat-the-string/

package reformatTheString;

class Solution {

	// time complexity: O(n): n = s.length()
	// space complexity: O(1)
    public String reformat(String s) {
		int[] alpha = new int[26];
		int[] digits = new int[10];
		int balance = 0;
		for (char c : s.toCharArray()) {
			if (Character.isLetter(c)) {
				alpha[c - 'a']++;
				balance++;
			} else {
				digits[c - '0']++;
				balance--;
			}
		}
		if (balance < -1 || balance > 1)
			return "";

		var stringBuilder = new StringBuilder();
		int i = 0;
		int j = 0;
		boolean digitTurn = balance < 0 ? true : false;
		while (i < alpha.length || j < digits.length) {
			while (i < alpha.length && alpha[i] == 0)
				i++;
			while (j < digits.length && digits[j] == 0)
				j++;
			if (i == alpha.length && j == digits.length)
				break;
			if (digitTurn || i == alpha.length) {
				stringBuilder.append((char)(j + '0'));
				digits[j]--;
			} else {
				stringBuilder.append((char)(i + 'a'));
				alpha[i]--;
			}
			digitTurn = !digitTurn;
		}

		return stringBuilder.toString();
    }
}
