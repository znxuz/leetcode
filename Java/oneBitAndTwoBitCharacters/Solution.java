// https://leetcode.com/problems/1-bit-and-2-bit-characters/

package oneBitAndTwoBitCharacters;

class Solution {

    public boolean isOneBitCharacter(int[] bits) {
		boolean found0 = false;
		int count = 0;
		for (int i = bits.length - 2; i >= 0 && !found0; i--) {
			if (bits[i] == 1)
				count++;
			else
				found0 = true;
		}

		return count % 2 == 0;
			
    }
}
