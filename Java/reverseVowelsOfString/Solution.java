// https://leetcode.com/problems/reverse-vowels-of-a-string/

package reverseVowelOfString;

import java.util.Stack;

class Solution {


	// time complexity: O(n)
	// space complexity: O(n)
    public String reverseVowelsStack(String s) {
		char[] array = s.toCharArray();
		char[] vowels = new char[s.length()];
		int top = -1;

		for (char c : array) {
			if (isVowel(c))
				vowels[++top] = c;
		}
		var strBuilder = new StringBuilder();
		for (char c : array) {
			strBuilder.append(isVowel(c) ? vowels[top--] : c);
		}

		return strBuilder.toString();
	}

    public String reverseVowelsStream(String s) {
		Stack<Integer> stack = new Stack<>();
		s.chars().filter(this::isVowel).forEach(stack::push);
		return s.chars()
			.map(c -> {
				if (isVowel(c))
					return stack.pop();
				return c;
			})
			.collect(StringBuilder::new,
				StringBuilder::appendCodePoint, StringBuilder::append)
			.toString();
	}

	private boolean isVowel(int c) {
		switch (Character.toLowerCase(c)) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				return true;
		}
		return false;
	}

}
