// https://leetcode.com/problems/add-strings/

package addStrings;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public String addStrings(String num1, String num2) {
		int i = num1.length() - 1;
		int j = num2.length() - 1;
		int carry = 0;
		StringBuilder strBuilder = new StringBuilder();
		int sum = 0;
		while (i >= 0 || j >= 0) {
			int digit1 = i < 0 ? 0 : num1.charAt(i) - '0';
			int digit2 = j < 0 ? 0 : num2.charAt(j) - '0';
			sum = digit1 + digit2 + carry;
			carry = sum % 10;
			strBuilder.append(String.valueOf(sum % 10));
			i--;
			j--;
		}
		if (carry != 0)
			strBuilder.append(carry);

		return strBuilder.reverse().toString();
    }
}
