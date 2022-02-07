// https://leetcode.com/problems/faulty-sensor/

package faultySensor;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public int badSensor(int[] sensor1, int[] sensor2) {
		int n = sensor1.length;
		int i = 0;
		while (i < n && sensor1[i] == sensor2[i])
			i++;
		int j = i;
		int k = i;
		while (j + 1 < n && sensor1[j + 1] == sensor2[j])
			j++;
		while (k + 1 < n && sensor1[k] == sensor2[k + 1])
			k++;
		if (i >= n - 1 || j == k)
			return -1;
		return j == n - 1 ? 2 : 1;
    }
}
