// https://leetcode.com/problems/roman-to-integer/

package romanToInt;

import java.util.HashMap;
import java.util.Map;

class Solution {

	private static final Map<Character, Integer> roman = new HashMap<>();
	static {
		roman.put('I', 1);
		roman.put('V', 5);
		roman.put('X', 10);
		roman.put('L', 50);
		roman.put('C', 100);
		roman.put('D', 500);
		roman.put('M', 1000);
	}

	// O(n) with O(1) lookup
    public int romanToInt(String s) {
		int sum = 0;
		int sLen = s.length();

		for (int i = 0; i < sLen; i++) {
			int cur = roman.get(s.charAt(i));
			int next = i < sLen - 1 ? roman.get(s.charAt(i + 1)) : 0;
			if (next != 0 && (next - cur == cur * 4 || next - cur == cur * 9)) {
				cur = next - cur;
				i++;
			}
			sum += cur;
		}

		return sum;
    }
}
