// https://leetcode.com/problems/maximum-units-on-a-truck/

package maximumUnitsOnATruck;

import java.util.Arrays;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
	public int maximumUnits(int[][] boxTypes, int truckSize) {
		int[] cnts = new int[1001];
		for (var type : boxTypes)
			cnts[type[1]] += type[0];

		int units = 0;
		for (int i = cnts.length - 1; i >= 0 && truckSize > 0; --i) {
			if (cnts[i] == 0)
				continue;
			units += i * Math.min(cnts[i], truckSize);
			truckSize -= cnts[i];
		}

		return units;
	}

	// time complexity: O(n logn)
	// space complexity: O(n)
	public int maximumUnitsSort(int[][] boxTypes, int truckSize) {
		Arrays.sort(boxTypes, (arr1, arr2) -> Integer.compare(arr1[1], arr2[1]) * -1);

		int units = 0;
		for (var type : boxTypes) {
			for (int i = 0; i < type[0] && truckSize > 0; ++i, truckSize--)
				units += type[1];
			if (truckSize == 0)
				break;
		}

		return units;
	}
}
