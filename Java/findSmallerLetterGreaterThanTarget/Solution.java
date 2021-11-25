// https://leetcode.com/problems/find-smallest-letter-greater-than-target/

package findSmallerLetterGreaterThanTarget;

class Solution {

	// Binary Search with inserting index
	// time complexity: O(logn)
	// space complexity: O(1)
    public char nextGreatestLetterBS(char[] letters, char target) {
		int left = 0;
		int right = letters.length;

		while (left < right) {
			int mid = left + (right - left) / 2;
			if (letters[mid] <= target)
				left = mid + 1;
			else
				right = mid;
		}

		return letters[left % letters.length];
    }

}
