// https://leetcode.com/problems/design-compressed-string-iterator/

package designCompressedStringIterator;

class Solution {
}

class StringIterator {

	private String str;
	private int length;
	private int index = 0;
	private char current;
	private int count = 0;

    public StringIterator(String compressedString) {
		str = compressedString;
		length = str.length();
    }

    public char next() {
		if (!hasNext())
			return ' ';
		if (count == 0) {
			current = str.charAt(index++);
			while (index < length && Character.isDigit(str.charAt(index)))
				count = count * 10 + str.charAt(index++) - '0';
		}
		count--;
		return current;
    }

    public boolean hasNext() {
		return index < length || count != 0;
    }
}

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
