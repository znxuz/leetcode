// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/

package checkIfOneStringSwapCanMakeStringsEqual;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public boolean areAlmostEqual(String s1, String s2) {
		char swap1 = 0;
		char swap2 = 0;
		int cnt = 0;
		for (int i = 0; i < s1.length(); ++i) {
			if (s1.charAt(i) != s2.charAt(i)) {
				if (cnt == 0) {
					swap1 = s1.charAt(i);
					swap2 = s2.charAt(i);
				} else if (s1.charAt(i) == swap2 && s2.charAt(i) == swap1) {
					swap1 = swap2 = 0;
				}
				cnt++;
			}
		}

		return swap1 == swap2 && cnt <= 2;
    }
}
