// https://leetcode.com/problems/check-if-string-is-decomposable-into-value-equal-substrings/

package checkIfStringIsDecomposableIntoValueEqualSubstrings;

class Solution {

    // time complexity: O(n)
    // space complexity: O(1)
    public boolean isDecomposable(String s) {
        int begin = 0;
        int end = 1;
        boolean found2 = false;
        while (begin != end) {
            if (end == s.length() || s.charAt(begin) != s.charAt(end)) {
                int distance = end - begin;
                if (distance < 2)
                    return false;
                if (distance % 3 != 0) {
                    if (found2)
                        return false;
                    found2 = true;
                }
                begin = end;
            }
            if (end < s.length())
                end++;
        }

        return found2;
    }
}
