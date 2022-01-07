// https://leetcode.com/problems/count-largest-group/

package countLargestGroup;

import java.util.HashMap;
import java.util.Map;

class Solution {

	// counting sort
	// constraints 1 <= n <= 10^4 = 10000
	// time complexity: O(n)
	// space compplexity: O(1)
    public int countLargestGroup(int n) {
		int[] map = new int[37];
		for (int i = 1; i <= n; ++i) {
			int num = i;
			int sum = 0;
			while (num > 0) {
				sum += num % 10;
				num /= 10;
			}
			map[sum]++;
		}
		int max = -1;
		int count = 1;
		for (int i = 0; i < map.length; ++i) {
			if (map[i] == 0 || max > map[i])
				continue;
			if (max < map[i])
				count = 1;
			else
				count++;
			max = map[i];
		}


		return count;
	}

	// time complexity: O(n)
	// space complexity: O(n)
    public int countLargestGroupBruteForce(int n) {
		Map<Integer, Integer> map = new HashMap<>();
		for (int i = 1; i <= n; ++i) {
			int sum = digitSum(i);
			map.put(sum, map.getOrDefault(sum, 0) + 1);
		}

		int max = 0;
		int count = 1;
		for (int size : map.values()) {
			if (size == max)
				count++;
			if (size > max) {
				max = size;
				count = 1;
			}
		}

		return count;
    }

	public int digitSum(int n) {
		if (n < 10)
			return n;
		return n % 10 + digitSum(n / 10);
	}
}
