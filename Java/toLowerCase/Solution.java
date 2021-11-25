// https://leetcode.com/problems/to-lower-case/

package toLowerCase;

class Solution {

    public String toLowerCase(String s) {
		StringBuilder stringBuilder = new StringBuilder();
		int len = s.length();
		for (int i = 0; i < len; i++) {
			char cur = s.charAt(i);
			if ((cur > 64 && cur < 91) || (cur > 96 && cur < 123))
				cur = (char)(s.charAt(i) | ' ');
			stringBuilder.append(cur);
		}

		return stringBuilder.toString();
    }
}
