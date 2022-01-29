// https://leetcode.com/problems/decode-xored-array/

package decodeXORedArray;

class Solution {

	// time complexity: O(n)
	// space complexity: O(n)
    public int[] decode(int[] encoded, int first) {
		int[] decoded = new int[encoded.length + 1];
		decoded[0] = first;
		for (int i = 1; i < decoded.length; ++i) {
			decoded[i] = decoded[i - 1] ^ encoded[i - 1];
		}

		return decoded;
    }
}
