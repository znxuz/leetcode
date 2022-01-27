// https://leetcode.com/problems/count-of-matches-in-tournament/

package countOfMatchesInTournament;

class Solution {

    public int numberOfMatchesSimulationConstTime(int n) {
		return n - 1;
	}

	// time complexity: O(n)
	// space complexity: O(1)
    public int numberOfMatchesSimulation(int n) {
		int cnt = 0;
		int match;
		while (n > 1) {
			match = n / 2;
			cnt += match;
			n = match + n % 2;
		}

		return cnt;
    }
}
