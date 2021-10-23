// https://leetcode.com/problems/binary-watch/

package binaryWatch;

import java.util.ArrayList;
import java.util.List;

class Solution {

    public List<String> readBinaryWatch(int turnedOn) {
		List<String> list = new ArrayList<>();
		for (int h = 0; h < 12; h++) {
			for (int m = 0; m < 60; m++) {
				if (Integer.bitCount(h) + Integer.bitCount(m) == turnedOn)
					list.add(String.format("%d:%02d", h, m));
			}
		}

		return list;
    }
}
