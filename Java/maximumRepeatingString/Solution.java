// https://leetcode.com/problems/maximum-repeating-substring/

package maximumRepeatingString;

class Solution {

	// time compleixty: O(n)
	// space complexity: (n)
    public int maxRepeating(String sequence, String word) {
		int cnt = 0;
		String find = word;
		while (sequence.contains(find)) {
			cnt++;
			find += word;
		}
		return cnt;
    }
}
