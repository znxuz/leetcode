// https://leetcode.com/problems/repeated-substring-pattern/

package repeatedSubstringPattern;

class Solution {

    public boolean repeatedSubstringPattern(String s) {
		String concat = s + s;
		return concat.substring(1, concat.length() - 1).contains(s);
    }
}
