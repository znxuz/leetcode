// https://leetcode.com/problems/jewels-and-stones/

package jewelsAndStones;

import java.util.HashSet;
import java.util.Set;

class Solution {

	// space complexity: O(1)
    public int numJewelsInStones(String jewels, String stones) {
		boolean[] flags = new boolean[52];
		int offset = 0;
		for (char c : jewels.toCharArray()) {
			offset = Character.isUpperCase(c) ? 'A' - 26 : 'a';
			flags[c - offset] = true;
		}

		int count = 0;
		for (char c : stones.toCharArray()) {
			offset = Character.isUpperCase(c) ? 'A' - 26 : 'a';
			if (flags[c - offset])
				count++;
		}

		return count;
	}

	// time complexity: O(n)
	// space complexity: O(n)
    public int numJewelsInStonesSet(String jewels, String stones) {
		Set<Character> set = new HashSet<>();
		for (char c : jewels.toCharArray())
			set.add(c);
		int count = 0;
		for (char c : stones.toCharArray())
			if (set.contains(c))
				count++;

		return count;
    }

}
