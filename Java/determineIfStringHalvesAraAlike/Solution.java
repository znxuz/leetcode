// https://leetcode.com/problems/determine-if-string-halves-are-alike/

package determineIfStringHalvesAraAlike;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public boolean halvesAreAlike(String s) {
		int lo = 0;
		int hi = s.length() - 1;
		int cnt = 0;
		while (lo < hi) {
			char left = Character.toLowerCase(s.charAt(lo++));
			char right = Character.toLowerCase(s.charAt(hi--));
			if (isVowel(left))
				cnt++;
			if (isVowel(right))
				cnt--;
		}

		return cnt == 0;
    }

	public boolean isVowel(char c) {
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
	}

}
