// https://leetcode.com/problems/minimum-moves-to-convert-string/

package minimumMovesToConvertString;

class Solution {

    public int minimumMoves(String s) {
		int cnt = 0;
		int i = 0;
		while (i < s.length()) {
			cnt += (s.charAt(i) == 'X') ? 1 : 0;
			i += (s.charAt(i) == 'X') ? 3 : 1;
		}

		return cnt;
    }
}
