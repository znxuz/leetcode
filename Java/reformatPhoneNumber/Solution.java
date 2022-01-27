// https://leetcode.com/problems/reformat-phone-number/

package reformatPhoneNumber;

import java.util.ArrayDeque;
import java.util.Deque;

class Solution {

    public String reformatNumber(String number) {
		return number.replaceAll("\\D", "").replaceAll("...?(?=..)", "$0-");
	}

	// time complexity: O(n)
	// space complexity: O(n)
    public String reformatNumberLinear(String number) {
		Deque<Character> q = new ArrayDeque<>();
		for (char c : number.toCharArray()) {
			if (Character.isDigit(c))
				q.offer(c);
		}
		int blocks = q.size() / 3;
		int rest = q.size() % 3;
		if (rest == 1)
			blocks--;
		var strBuilder = new StringBuilder();
		while (blocks-- > 0) {
			for (int i = 0; i < 3; ++i)
				strBuilder.append(q.poll());
			if (!q.isEmpty())
				strBuilder.append('-');
		}
		int cnt = 0;
		while (!q.isEmpty()) {
			strBuilder.append(q.poll());
			if (rest == 1 && cnt == 1)
				strBuilder.append('-');
			cnt++;
		}

		return strBuilder.toString();
    }
}
