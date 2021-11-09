// https://leetcode.com/problems/reverse-words-in-a-string-iii/

package reverseWordsInStringIII;

class Solution {

	// time complexity: O(n)
	// space complexity: O(n)
    public String reverseWords(String s) {
		var stringBuilder = new StringBuilder();
		int len = s.length();
		int begin, end;
		begin = end = 0;
		for (int i = 0; i < len; i++) {
			begin = i;
			while (i < len && !Character.isWhitespace(s.charAt(i)))
				i++;
			end = i;
			while (end-- > begin)
				stringBuilder.append(s.charAt(end));
			if (i < len)
				stringBuilder.append(s.charAt(i));
		}

		return stringBuilder.toString();
    }
}
