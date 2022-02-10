// https://leetcode.com/problems/largest-odd-number-in-string/

package largestOddNumberInString;

class Solution {

    // time complexity: O(n)
    // space complexity: O(1)
    public String largestOddNumber(String num) {
        for (int i = num.length() - 1; i >= 0; --i) {
            char c = num.charAt(i);
            if (Character.isDigit(c) && c % 2 != 0)
                return num.substring(0, i + 1);
        }

        return "";
    }
}
