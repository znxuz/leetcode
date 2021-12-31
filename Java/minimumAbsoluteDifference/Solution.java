// https://leetcode.com/problems/minimum-absolute-difference/

package minimumAbsoluteDifference;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {

	// constraints: -10^6 <= arr[i] <= 10^6
	// time complexity: O(n)
	// space complexity: O(max(arr[i]) - min(arr[i]))
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
		int[] negatives = new int[1000001];
		int[] neutrals = new int[1000001];
		for (int n : arr) {
			if (n < 0)
				negatives[Math.abs(n)]++;
			else
				neutrals[n]++;
		}

		List<List<Integer>> list = new ArrayList<>();
		int minDiff = Integer.MAX_VALUE;
		boolean checkNegatives = true;
		int anchor = -1;
		for (int i = negatives.length - 1; i >= 0; --i) {
			if (negatives[i] == 0)
				continue;
			if (anchor != -1) {
				int diff = anchor - i;
				if (diff <= minDiff) {
					if (diff < minDiff) {
						list.clear();
						minDiff = diff;
					}
					list.add(Arrays.asList(-anchor, -i));
				}
			}
			anchor = i;
		}
		for (int i = 0; i < neutrals.length; ++i) {
			if (neutrals[i] == 0)
				continue;
			if (anchor != -1) {
				int diff = i - (checkNegatives ? -anchor : anchor);
				if (diff <= minDiff) {
					if (diff < minDiff) {
						list.clear();
						minDiff = diff;
					}
					list.add(Arrays.asList(checkNegatives ? -anchor : anchor, i));
				}
			}
			anchor = i;
			checkNegatives = false;
		}

		return list;
	}

	// time complexity: O(n logn)
	// space complexity: O(n) for sorting
    public List<List<Integer>> minimumAbsDifferenceSort(int[] arr) {
		Arrays.sort(arr);
		List<List<Integer>> list = new ArrayList<>();
		int minDiff = Integer.MAX_VALUE;
		for (int i = 1; i < arr.length; ++i) {
			int diff = arr[i] - arr[i - 1];
			if (diff > minDiff)
				continue;
			if (diff < minDiff) {
				list.clear();
				minDiff = diff;
			}
			list.add(Arrays.asList(arr[i - 1], arr[i]));
		}

		return list;
    }
}
