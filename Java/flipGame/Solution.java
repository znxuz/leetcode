// https://leetcode.com/problems/flip-game/

package flipGame;

import java.util.ArrayList;
import java.util.List;

class Solution {

    public List<String> generatePossibleNextMoves(String currentState) {
		List<String> list = new ArrayList<>();

		for (int i = 0; i < currentState.length() - 1; i++) {
			if (currentState.substring(i, i + 2).equals("++"))
				list.add(currentState.substring(0, i) + "--"
						+ currentState.substring(i + 2, currentState.length()));
		}

		return list;
    }
}
