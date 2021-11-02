// https://leetcode.com/problems/license-key-formatting/

package licenseKeyFormatting;

class Solution {

    public String licenseKeyFormatting(String s, int k) {
		StringBuilder stringBuilder = new StringBuilder();
		int counter = 0;
		for (int i = s.length() - 1; i >= 0; i--) {
			if (s.charAt(i) == '-')
				continue;
			if (counter == k) {
				stringBuilder.append('-');
				counter = 0;
			}
			stringBuilder.append(Character.toUpperCase(s.charAt(i)));
			counter++;
		}

		return stringBuilder.reverse().toString();
    }
}
