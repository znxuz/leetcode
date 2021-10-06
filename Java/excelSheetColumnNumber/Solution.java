// https://leetcode.com/problems/excel-sheet-column-number/

package excelSheetColumnNumber;

class Solution {

	// recursion starting from the end
	// time complexity: O(n)
	// space complexity: O(n)
	private int titleToNumberRec(char[] title, int index, int exponent) {
		int result = (title[index] - 'A' + 1) * (int)Math.pow(26, exponent);
		if (index == 0)
			return result;
		return result + titleToNumberRec(title, --index, ++exponent);
	}

    public int titleToNumber(String columnTitle) {
		return titleToNumberRec(columnTitle.toCharArray(), columnTitle.length() - 1, 0);
	}

	// java Stream
    public int titleToNumberStream(String columnTitle) {
		return columnTitle.chars().reduce(0, (sum, elem) -> sum * 26 + (elem - 'A' + 1));
    }
}
