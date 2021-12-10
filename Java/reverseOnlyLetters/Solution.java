// https://leetcode.com/problems/reverse-only-letters/

package reverseOnlyLetters;

class Solution {

	// time complexity: O(n)
	// space complexity: O(n)
    public String reverseOnlyLetters(String s) {
		StringBuilder stringBuilder = new StringBuilder();
		int left = 0;
		int right = s.length() - 1;
		while (left < s.length()) {
			if (Character.isLetter(s.charAt(left))) {
				while (!Character.isLetter(s.charAt(right)))
					right--;
				stringBuilder.append(s.charAt(right--));
			} else {
				stringBuilder.append(s.charAt(left));
			}
			left++;
		}

		return stringBuilder.toString();
    }
}
