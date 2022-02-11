// https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/

package checkIfAllCharactersHaveEqualNumOfOccurrences;

class Solution {

    public boolean areOccurrencesEqual(String s) {
        int[] cnts = new int[26];
        for (char c : s.toCharArray())
            cnts[c - 'a']++;

        int c = 0;
        for (int i = 0; i < cnts.length; ++i) {
            if (cnts[i] != 0) {
                if (c == 0)
                    c = cnts[i];
                else if (cnts[i] != c)
                    return false;
            }
        }
        return true;
    }
}
