// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

package removeAllAdjacentDuplicatesInString;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Solution {

	// time complexity: O(n)
	// space complexity: O(n)
    public String removeDuplicatesStack(String s) {
		var stringBuilder = new StringBuilder();
		for (char c : s.toCharArray()) {
			int len = stringBuilder.length();
			if (len == 0 || stringBuilder.charAt(len - 1) != c)
				stringBuilder.append(c);
			else
				stringBuilder.deleteCharAt(len - 1);
		}

		return stringBuilder.toString();
	}

	// time limit exceeded
    public String removeDuplicates(String s) {
		Pattern p = Pattern.compile("([a-zA-Z])\\1");
		Matcher m = p.matcher(s);
		while (m.find()) {
			s = m.replaceAll("");
			m.reset(s);
		}

		return s;
	}

}
