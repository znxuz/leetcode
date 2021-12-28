// https://leetcode.com/problems/day-of-the-year/

package dayOfTheYear;

import java.util.Arrays;
import java.util.GregorianCalendar;

class Solution {

    public int dayOfYear(String date) {
		var d = Arrays.stream(date.split("-"))
			.mapToInt(Integer::parseInt)
			.toArray();
		int ctr = 0;
		int leap = new GregorianCalendar().isLeapYear(d[0]) ?
			1 : 0;
        int[] days = {31, 28 + leap, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		for (int i = 0; i < d[1] - 1; ++i)
			ctr += days[i];

		return ctr + d[2];
    }

}
