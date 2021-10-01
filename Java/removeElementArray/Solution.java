package removeElementArray;

import java.util.Arrays;

class Solution {

    public int removeElement(int[] nums, int val) {
		int i = 0;
		for (int j = 0; j < nums.length; j++) {
			if (nums[j] != val) {
				nums[i] = nums[j];
				i++;
			}
		}

		return i;
	}

    public int removeElementStream(int[] nums, int val) {
		int[] clean = Arrays.stream(nums).filter(x -> x != val).toArray();
		for (int i = 0; i < clean.length; i++) {
			nums[i] = clean[i];
		}
		return clean.length;
    }
}
