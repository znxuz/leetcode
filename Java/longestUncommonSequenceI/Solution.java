// https://leetcode.com/problems/longest-uncommon-subsequence-i/

package longestUncommonSequenceI;

class Solution {

    public int findLUSlength(String a, String b) {
		return a.equals(b) ? -1 : Math.max(a.length(), b.length());
    }
}
