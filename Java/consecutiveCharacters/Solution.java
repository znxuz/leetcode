// https://leetcode.com/problems/consecutive-characters/

package consecutiveCharacters;

class Solution {

    public int maxPower(String s) {
		int power = 0;
		int max = 0;
		char prev = 0;
		for (char c : s.toCharArray()) {
			if (prev == 0 || c != prev) {
				prev = c;
				power = 1;
			} else {
				power++;
			}
			max = Math.max(max, power);
		}

		return max;
    }
}
