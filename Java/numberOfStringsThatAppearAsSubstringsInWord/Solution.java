// https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/

package numberOfStringsThatAppearAsSubstringsInWord;

class Solution {

    // time complexity: O(n * m): n for word.length(), m for patterns.length
    // space complexity: O(1)
    public int numOfStrings(String[] patterns, String word) {
        int cnt = 0;
        for (var p : patterns)
            if (word.contains(p))
                cnt++;
        return cnt;
    }

    // time complexity: O(n * m): n for word.length(), m for patterns.length
    // space complexity: O(1)
    public int numOfStringsBruteForce(String[] patterns, String word) {
        int cnt = 0;
        for (var p : patterns) {
            for (int i = 0; i < word.length() - p.length() + 1; ++i) {
                int j = 0;
                while (j < p.length() && p.charAt(j) == word.charAt(i + j))
                    j++;
                if (j == p.length()) {
                    cnt++;
                    break;
                }
            }
        }

        return cnt;
    }
}
