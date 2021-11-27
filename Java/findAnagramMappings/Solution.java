// https://leetcode.com/problems/find-anagram-mappings/

package findAnagramMappings;

import java.util.HashMap;
import java.util.Map;

class Solution {

	// time complexity: O(n)
	// spcae complexity: O(n)
	// does not work with duplicates
	// if duplicates and preserve order, use Quque isntead of Integer for map.values
    public int[] anagramMappings(int[] nums1, int[] nums2) {
		Map<Integer, Integer> map = new HashMap<>();
		for (int i = 0; i < nums2.length; i++) {
			map.put(nums2[i], i);
		}

		int[] idx = new int[nums1.length];
		for (int i = 0; i < idx.length; i++) {
			idx[i] = map.get(nums1[i]);
		}

		return idx;
    }

}
