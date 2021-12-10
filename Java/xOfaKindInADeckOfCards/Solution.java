// https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/

package xOfaKindInADeckOfCards;

import java.util.HashMap;
import java.util.Map;

class Solution {

    public boolean hasGroupsSizeX(int[] deck) {
		Map<Integer, Integer> map = new HashMap<>();
		for (int i : deck) {
			map.put(i, map.getOrDefault(i, 0) + 1);
		}

		int res = 0;
		for (int i : map.values())
			res = gcd(i, res);

		return res > 1;
    }

	private int gcd(int a, int b) {
		return b > 0 ? gcd(b, a % b) : a;
	}

}
