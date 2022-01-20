// https://leetcode.com/problems/crawler-log-folder/

package crawlerLogFolder;

class Solution {

	// time complexity: O(n * m): m for length of each log
	// space complexity: O(1)
    public int minOperations(String[] logs) {
		int cnt = 0;
		for (var l : logs) {
			if (l.equals("../")) {
				cnt = Math.max(cnt - 1, 0);
			} else if (!l.equals("./")) {
				cnt++;
			}

		}

		return cnt;
    }
}
