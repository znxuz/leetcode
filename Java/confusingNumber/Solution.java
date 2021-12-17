// https://leetcode.com/problems/confusing-number/

package confusingNumber;

import java.util.HashMap;
import java.util.Map;

class Solution {

	private final Map<Integer, Integer> map = new HashMap<>();
	{
		map.put(0, 0);
		map.put(1, 1);
		map.put(6, 9);
		map.put(8, 8);
		map.put(9, 6);
	}

    public boolean confusingNumber(int n) {
		int rotated = 0;
		int num = n;
		while (n > 0) {
			int last = n % 10;
			if (!map.containsKey(last))
				return false;
			rotated = rotated * 10 + map.get(last);
			n /= 10;
		}

		return rotated != num;
    }

}
