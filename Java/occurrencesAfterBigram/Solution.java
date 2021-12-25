// https://leetcode.com/problems/occurrences-after-bigram/

package occurrencesAfterBigram;

import java.util.ArrayList;
import java.util.List;

class Solution {

	// time complexity: O(n)
	// space complexity: O(n)
    public String[] findOcurrences(String text, String first, String second) {
		var arr = text.split("\\s+");
		List<String> list = new ArrayList<>();
		for (int i = 0; i < arr.length - 2; ++i) {
			if (arr[i].equals(first) && arr[i + 1].equals(second) && i + 2 < arr.length)
				list.add(arr[i + 2]);
		}

		return list.stream().toArray(String[]::new);
    }
}
