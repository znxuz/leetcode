// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/

package minimumChangesToMakeAlternatingBinaryString;

class Solution {

	// time complexity; O(n)
	// space complexity: O(1)
    public int minOperationsOnePass(String s) {
		int begin = 0;
		int cnt1 = 0;
		int cnt2 = 0;
		for (char c : s.toCharArray()) {
			if (c - '0' == begin)
				cnt1++;
			else
				cnt2++;
			begin ^= 1;
		}

		return Math.min(cnt1, cnt2);
    }

	// time complexity; O(n)
	// space complexity: O(1)
    public int minOperations(String s) {
		int cnt1 = 0;
		int begin = 0;
		for (char c : s.toCharArray()) {
			if (c - '0' != begin)
				cnt1++;
			begin ^= 1;
		}
		begin = 1;
		int cnt2 = 0;
		for (char c : s.toCharArray()) {
			if (c - '0' != begin)
				cnt2++;
			begin ^= 1;
		}

		return Math.min(cnt1, cnt2);
    }
}
