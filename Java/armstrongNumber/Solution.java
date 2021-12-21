// https://leetcode.com/problems/armstrong-number/

package armstrongNumber;

class Solution {

    public boolean isArmstrong(int n) {
		int count = 0;
		for (int i = n; i > 0; i /= 10)
			count++;
		int sum = 0;
		for (int i = n; i > 0; i /= 10)
			sum += Math.pow(i % 10, count);

		return sum == n;
    }
}
