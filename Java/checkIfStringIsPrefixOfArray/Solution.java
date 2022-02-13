// https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/

package checkIfStringIsPrefixOfArray;

class Solution {

    // time complexity: O(n)
    // space complexity: O(1)
    public boolean isPrefixString(String s, String[] words) {
        int i = 0;
        for (int j = 0; j < words.length && i < s.length(); ++j) {
            for (char c : words[j].toCharArray()) {
                if (i == s.length() || s.charAt(i) != c)
                    return false;
                i++;
            }
        }
        return i == s.length();
    }
}
