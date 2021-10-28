// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

package findAllNumbersDisappearedinArray;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;

class Solution {

	// time complexity: O(n)
	// space complexity: O(n)
    public List<Integer> findDisappearedNumbersFlags(int[] nums) {
		List<Integer> list = new ArrayList<>();
		boolean[] flags = new boolean[nums.length];
		for (int i : nums)
			flags[i - 1] = true;
		for (int i = 0; i < flags.length; i++) {
			if (!flags[i])
				list.add(i + 1);
		}

		return list;
	}

	// time complexity: O(n)
	// space complexity: O(1)
    public List<Integer> findDisappearedNumbers(int[] nums) {
		List<Integer> list = new ArrayList<>();
		for (int i = 0; i < nums.length; i++) {
			int index = Math.abs(nums[i]) - 1;
			if (nums[index] > 0)
				nums[index] *= -1;
		}
		for (int i = 0; i < nums.length; i++) {
			if (nums[i] > 0)
				list.add(i + 1);
		}
		for (int i = 0; i < nums.length; i++) {
			nums[i] = Math.abs(nums[i]);
		}

		return list;
	}

    public List<Integer> findDisappearedNumbersTreeSet(int[] nums) {
		List<Integer> list = new ArrayList<>();
		Set<Integer> set = new TreeSet<>();
		for (int i : nums)
			set.add(i);
		Iterator<Integer> iterator = set.iterator();
		for (int i = 1; i <= nums.length; i++) {
			int cur = iterator.hasNext() ? iterator.next() : nums.length + 1;
			if (i != cur) {
				while (i < cur)
					list.add(i++);
			}
		}

		return list;
    }
}
