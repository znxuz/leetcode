// https://leetcode.com/problems/path-crossing/

package pathCrossing;

import java.util.HashSet;
import java.util.Set;

class Solution {

	// time complexity: O(n)
	// space complexity: O(n)
    public boolean isPathCrossing(String path) {
		Set<Integer> visited = new HashSet<>();
		int x = 0;
		int y = 0;
		visited.add(0);
		for (char d : path.toCharArray()) {
			if (d == 'N')
				y++;
			if (d == 'S')
				y--;
			if (d == 'W')
				x--;
			if (d == 'E')
				x++;
			if (!visited.add(x * 20001 + y))
				return true;
		}

		return false;
    }
}
