// https://leetcode.com/problems/shortest-word-distance/

package shortestWordDistance;

import java.util.ArrayList;
import java.util.List;

class Solution {

	// time complexity: O(m * n)
	// space complexity: O(1)
    public int shortestDistance(String[] words, String word1, String word2) {
		int i1 = -1;
		int i2 = -1;

		int min = Integer.MAX_VALUE;
		for (int i = 0; i < words.length; i++) {
			if (words[i].equals(word1))
				i1 = i;
			else if (words[i].equals(word2))
				i2 = i;

			if (i1 != -1 && i2 != -1)
				min = Math.min(min, Math.abs(i1 - i2));
		}

		return min;
	}

	// time complexity: O(m * n^2)
	// space complexity: O(1)
    public int shortestDistanceBruteForce(String[] wordsDict, String word1, String word2) {
		int min = Integer.MAX_VALUE;

		for (int i = 0; i < wordsDict.length; i++) {
			var cur = wordsDict[i];
			int distance = 0;
			if (word1.equals(cur))
				distance = getDistance(wordsDict, i, word2);
			if (word2.equals(cur))
				distance = getDistance(wordsDict, i, word1);
			if (distance != 0)
				min = min > distance ? distance : min;
		}

		return min;
    }

	private int getDistance(String[] words, int index, String target) {
		for (int i = index + 1; i < words.length; i++) {
			if (words[i].equals(target))
				return i - index;
		}
	
		return 0;
	}

}
