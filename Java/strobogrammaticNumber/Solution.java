// https://leetcode.com/problems/strobogrammatic-number/

package strobogrammaticNumber;

import java.util.HashMap;
import java.util.Map;

class Solution {

	private final Map<Integer, Integer> map = new HashMap<>();

	{
		map.putAll(Map.of(0, 0, 1, 1, 6, 9, 8, 8, 9, 6));
	};


    public boolean isStrobogrammatic(String str) {
		if (str == null)
			return true;
		
        for (int left = 0, right = str.length() - 1; left <= right; left++, right--) {
            int leftChar = str.charAt(left) - '0';
            int rightChar = str.charAt(right) - '0';            
            if (!map.containsKey(leftChar)
					|| map.get(leftChar) != rightChar)
                return false;
        }

		return true;
}

	// numStr.length() too long to be converted
	// slow runtime
    public boolean isStrobogrammaticStream(String str) {
		return str
			.chars()
			.map(c -> c - '0')
			.filter(map::containsKey)
			.map(map::get)
			.map(c -> c + '0')
			.collect(StringBuilder::new,
					StringBuilder::appendCodePoint,
					StringBuilder::append)
			.reverse()
			.toString()
			.equals(str);
    }
}
