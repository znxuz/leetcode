// https://leetcode.com/problems/delete-characters-to-make-fancy-string/

package deleteCharactersToMakeFancyString;

class Solution {

	// time complexity: O(n)
	// space complexity: O(n)
    public String makeFancyString(String s) {
		var stringBuilder = new StringBuilder();
		char a, b;
		a = b = 0;
		for (char c : s.toCharArray()) {
			if (c != b || c != a)
				stringBuilder.append(c);
			a = b;
			b = c;
		}

		return stringBuilder.toString();
	}

	// regex
    public String makeFancyStringRegex(String s) {
		return s.replaceAll("([a-zA-Z])(\\1{2,})", "$1$1");
    }
}
