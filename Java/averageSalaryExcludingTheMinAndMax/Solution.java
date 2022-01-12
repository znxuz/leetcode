// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/

package averageSalaryExcludingTheMinAndMax;

import java.util.Arrays;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public double average(int[] salary) {
		int max = salary[0];
		int min = salary[0];
		double sum = 0;
		for (int s : salary) {
			max = Math.max(max, s);
			min = Math.min(min, s);
			sum += s;
		}

		return (sum - max - min) / (salary.length - 2);
	}

	// time complexity: O(n logn)
	// space complexity: O(n) for sorting
    public double averageSort(int[] salary) {
		Arrays.sort(salary);
		double sum = 0;
		for (int i = 1; i < salary.length - 1; ++i)
			sum += salary[i];

		return sum / (salary.length - 2);
    }
}
