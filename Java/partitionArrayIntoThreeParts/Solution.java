// https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/

package partitionArrayIntoThreeParts;

class Solution {

    public boolean canThreePartsEqualSum(int[] arr) {
		int sum = 0;
		for (int i : arr)
			sum += i;
		int part = sum / 3;
		int tmp = 0;
		int ctr = 0;
		for (int i : arr) {
			tmp += i;
			if (tmp == part) {
				ctr++;
				tmp = 0;
			}
		}

		return sum % 3 == 0 && ctr >= 3;
    }
}
