// https://leetcode.com/problems/number-of-days-between-two-dates/

package numberOfDaysBetweenTwoDates;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

class Solution {

	// date API
    public int daysBetweenDates(String date1, String date2) {
		SimpleDateFormat format = new SimpleDateFormat("yyyy-MM-dd");
		try {
			Date d1 = format.parse(date1);
			Date d2 = format.parse(date2);
			long diff = Math.abs(d1.getTime() - d2.getTime()) / 1000 / 60 / 60 / 24;
			return (int)diff;
		} catch (ParseException e) {
			e.printStackTrace();
		}

		return 0;
    }

}
