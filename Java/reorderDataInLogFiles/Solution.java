// https://leetcode.com/problems/reorder-data-in-log-files/

package reorderDataInLogFiles;

import java.util.Arrays;
import java.util.Comparator;
import java.util.function.Predicate;

class Solution {

    public String[] reorderLogFiles(String[] logs) {
		Comparator<String> comp = (s1, s2) -> {
			Predicate<String> isNumeric = s -> s.chars().allMatch(Character::isDigit);
			var words1 = s1.replaceFirst("\\w+ ", "").split("\\s");
			var words2 = s2.replaceFirst("\\w+ ", "").split("\\s");
			var isDigitLog1 = isNumeric.test(words1[0]);
			var isDigitLog2 = isNumeric.test(words2[0]);
			if (isDigitLog1 && isDigitLog2)
				return 0;
			else if (isDigitLog1)
				return 1;
			else if (isDigitLog2)
				return -1;

			var res = Arrays.compare(words1, words2);
			if (res != 0)
				return res;
			return s1.split("\\s")[0].compareTo(s2.split("\\s")[0]);
		};

		Arrays.sort(logs, comp);

		return logs;
    }

}
