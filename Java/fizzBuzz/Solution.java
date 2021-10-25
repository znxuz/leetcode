// https://leetcode.com/problems/fizz-buzz/

package fizzBuzz;

import java.util.ArrayList;
import java.util.List;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public List<String> fizzBuzzNaive(int n) {
		List<String> list = new ArrayList<>();
		for (int i = 1; i <= n; i++) {
			if (i % 3 == 0 && i % 5 == 0)
				list.add("FizzBuzz");
			else if (i % 3 == 0)
				list.add("Fizz");
			else if (i % 5 == 0)
				list.add("Buzz");
			else
				list.add(String.valueOf(i));
		}

		return list;
    }
}
