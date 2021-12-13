// https://leetcode.com/problems/valid-mountain-array/

package validMountainArray;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public boolean validMountainArray(int[] arr) {
		if (arr == null || arr.length < 3)
			return false;

		boolean anchor = false;
		for (int i = 0; i < arr.length - 1; ++i) {
			int diff = arr[i + 1] - arr[i];
			if (diff == 0) {
				return false;
			} else if (diff < 0) {
				if (i == 0)
					return false;
				if (!anchor)
					anchor = true;
			} else {
				if (anchor)
					return false;
			} 
		}

		return anchor;
    }
}
