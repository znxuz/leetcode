// https://leetcode.com/problems/shortest-distance-to-a-character/

package shortestDistanceToCharacter;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public int[] shortestToChar(String s, char c) {
		int length = s.length();
		int[] ret = new int[length];
		int prev = -1;
		int next = -1;

		for (int i = 0; i < length; i++) {
			if (i >= next) {
				prev = next == -1 ? prev : next;
				next = findNext(s, i, c);
			}
			if (prev == -1)
				prev = next;
			if (next == -1)
				ret[i] = i - prev;
			else
				ret[i] = Math.min(next - i, Math.abs(i - prev));
		}

		return ret;
    }

	private int findNext(String s, int begin, char c) {
		for (int i = begin; i < s.length(); i++)
			if (s.charAt(i) == c)
				return i;
		return -1;
	}
}
