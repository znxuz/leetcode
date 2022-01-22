// https://leetcode.com/problems/slowest-key/

package slowestKey;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public char slowestKey(int[] releaseTimes, String keysPressed) {
		int max = 0;
		char key = 0;
		for (int i = 0; i < keysPressed.length(); ++i) {
			char cur = keysPressed.charAt(i);
			int duration = releaseTimes[i] - ((i == 0) ? 0 : releaseTimes[i - 1]);
			if (duration > max || (duration == max && cur > key)) {
				max = duration;
				key = cur;
			}
		}

		return key;
	}

	// time complexity: O(n)
	// space complexity: O(1)
    public char slowestKeyTwoPass(int[] releaseTimes, String keysPressed) {
		int[] durations = new int[26];
		for (int i = 0; i < keysPressed.length(); ++i) {
			int cur = keysPressed.charAt(i) - 'a';
			durations[cur] = Math.max(durations[cur],
					releaseTimes[i] - ((i == 0) ? 0 : releaseTimes[i - 1]));
		}

		int max = 0;
		char key = 0;
		for (int i = 0; i < durations.length; ++i) {
			if (durations[i] >= max) {
				max = durations[i];
				key = (char)(i + 'a');
			}
		}

		return key;
    }
}
