// https://leetcode.com/problems/reformat-date/

package reformatDate;

import java.time.Month;
import java.util.Arrays;
import java.util.regex.Pattern;

class Solution {

	// with built-in api Month
    public String reformatDate(String date) {
		String[] split = date.split("\\s");
		String year = split[2];
		int month = Arrays.stream(Month.values())
			.filter(m ->
					Pattern.compile(split[1] + ".*", Pattern.CASE_INSENSITIVE).matcher(m.name()).matches())
			.findFirst()
			.get().getValue();
		String day = (split[0].length() < 4 ? "0" : "") + split[0].replaceAll("[a-zA-Z]+", "");

		return new StringBuilder()
			.append(year)
			.append('-')
			.append((month < 10 ? "0" : "") + month)
			.append('-')
			.append(day)
			.toString();
    }

}
