// https://leetcode.com/problems/hexspeak/

package hexspeak;

class Solution {

    public String toHexspeak(String num) {
		var hex = toHex(Long.parseLong(num));
		var stringBuilder = new StringBuilder();
		for (char c : hex.toCharArray()) {
			if (c > '1' && c <= '9')
				return "ERROR";
			if (c == '0')
				c = 'O';
			if (c == '1')
				c = 'I';
			stringBuilder.append(Character.toUpperCase(c));
		}

		return stringBuilder.toString();
    }

	private String toHex(long num) {
		if (num == 0)
			return "0";

		final String hex = "0123456789ABCDEF";
		var stringBuilder = new StringBuilder();
		while (num > 0) {
			stringBuilder.append(hex.charAt((int)num & 15));
			num >>>= 4;
		}

		return stringBuilder.reverse().toString();
	}

}
