// https://leetcode.com/problems/find-the-town-judge/

package findTheTownJudge;

class Solution {

	// solution page:
	// 	https://leetcode.com/problems/find-the-town-judge/solution/
	// 	if ones trusts someone he has to spend a coin
	// 	if he get trusted from one he gets a coin
	// 	return the one who has a coin from all others (n - 1)
	// time complexity: O(n)
	// space complexity: O(n)
    public int findJudge(int n, int[][] trust) {
		int[] degrees = new int[n + 1];
		for (var pair : trust) {
			degrees[pair[0]]--;
			degrees[pair[1]]++;
		}

		for (int i = 1; i < degrees.length; ++i) {
			if (degrees[i] == n - 1)
				return i;
		}

		return -1;
    }
}
