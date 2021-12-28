// https://leetcode.com/problems/diet-plan-performance/

package dietPlanPerformance;

class Solution {

	// sliding window
	// time complexity: O(n)
	// space complexity: O(1)
    public int dietPlanPerformance(int[] calories, int k, int lower, int upper) {
		int performance = 0;
		int sum = 0;
		for (int i = 0; i < calories.length; ++i) {
			sum += calories[i];
			if (i < k - 1)
				continue;
			if (sum < lower)
				performance--;
			if (sum > upper)
				performance++;
			sum -= calories[i - k + 1];
		}

		return performance;
	}

	// bad
	// time complexity: O(n^2)
	// space complexity: O(1)
    public int dietPlanPerformanceBruteForce(int[] calories, int k, int lower, int upper) {
		int performance = 0;
		for (int i = 0; i < calories.length - k + 1; ++i) {
			int sum = 0;
			for (int j = i; j < i + k; ++j)
				sum += calories[j];
			if (sum < lower)
				performance--;
			if (sum > upper)
				performance++;
		}

		return performance;
    }

}
