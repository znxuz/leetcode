// https://leetcode.com/problems/thousand-separator/

package thousandSeparator;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public String thousandSeparatorBuildString(int n) {
		if (n == 0)
			return "0";

		var stringBuilder = new StringBuilder();
		int cnt = 0;
		while (n > 0) {
			stringBuilder.append(n % 10);
			n /= 10;
			cnt = (cnt + 1) % 3;
			if (cnt == 0 && n > 0)
				stringBuilder.append('.');
		}

		return stringBuilder.reverse().toString();
    }
}
