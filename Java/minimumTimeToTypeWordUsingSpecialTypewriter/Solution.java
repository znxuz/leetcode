// https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/

package minimumTimeToTypeWordUsingSpecialTypewriter;

class Solution {

    public int minTimeToType(String word) {
        int cnt = 0;
        int ptr = 'a';
        for (char c : word.toCharArray()) {
            int d = Math.abs(c - ptr);
            cnt += Math.min(d, 26 - d) + 1;
            ptr = c;
        }
        return cnt;
    }
}
