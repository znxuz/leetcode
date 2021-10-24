// https://leetcode.com/problems/convert-a-number-to-hexadecimal/

package convertNumberToHexadecimal;

class Solution {

	private final char[] hex = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'a', 'b', 'c', 'd', 'e', 'f'};

    public String toHex(int num) {
		if (num == 0)
			return "0";

		var stringBuilder = new StringBuilder();
		while (num != 0) {
			stringBuilder.append(hex[num & 15]);
			num >>>= 4;
		}

		return stringBuilder.reverse().toString();
    }
}
