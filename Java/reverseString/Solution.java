// https://leetcode.com/problems/reverse-string/

package reverseString;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public void reverseStringTwoPointer(char[] s) {
		int left = 0;
		int right = s.length - 1;
		while (left < right) {
			char tmp = s[left];
			s[left] = s[right];
			s[right] = tmp;
			left++;
			right--;
		}
    }
}
