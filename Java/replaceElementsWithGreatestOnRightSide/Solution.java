// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

package replaceElementsWithGreatestOnRightSide;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public int[] replaceElements(int[] arr) {
		int prev = -1;
		int tmp = -1;
		for (int i = arr.length - 1; i >= 0; --i) {
			tmp = arr[i];
			arr[i] = (i == arr.length - 1) ? prev : Math.max(arr[i + 1], prev);
			prev = tmp;
		}

		return arr;
	}

	// time complexity: O(n)
	// space complexity: O(n)
    public int[] replaceElementsNSpace(int[] arr) {
		int[] ret = new int[arr.length];
		for (int i = arr.length - 1; i >= 0; --i) {
			if (i == arr.length - 1)
				ret[i] = -1;
			else
				ret[i] = Math.max(ret[i + 1], arr[i + 1]);
		}

		return ret;
    }
}
