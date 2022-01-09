// https://leetcode.com/problems/string-matching-in-an-array/

package stringMatchingInArray;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

class Solution {

    public List<String> stringMatchingBruteForce(String[] words) {
		Arrays.sort(words, Comparator.comparingInt(String::length));
		List<String> res = new ArrayList<>();
		for (int i = 0; i < words.length; ++i) {
			for (int j = i + 1; j < words.length; ++j) {
				if (words[j].indexOf(words[i]) != -1) {
					res.add(words[i]);
					break;
				}
			}
		}

		return res;
    }
}
