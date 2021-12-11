// https://leetcode.com/problems/unique-email-addresses/

package uniqueEmailAddresses;

import java.util.HashSet;
import java.util.Set;

class Solution {

    public int numUniqueEmails(String[] emails) {
		Set<String> set = new HashSet<>();
		for (var email : emails) {
			set.add(filter(email));
		}

		return set.size();
    }

	private String filterRegex(String email) {
		String[] parts = email.split("@");
		return parts[0].replaceAll("\\+.*|\\.", "") + "@" + parts[1];
	}

	private String filter(String email) {
		var stringBuilder = new StringBuilder();
		int i = 0;
		boolean ignore = false;
		while (i < email.length()) {
			char cur = email.charAt(i);
			if (cur == '@')
				break;
			if (cur == '+')
				ignore = true;

			if (!ignore && cur != '.')
				stringBuilder.append(cur);
			i++;
		}

		return stringBuilder.append(email.substring(i)).toString();
	}

}
