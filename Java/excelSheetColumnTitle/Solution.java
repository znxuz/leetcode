// https://leetcode.com/problems/excel-sheet-column-title/

package excelSheetColumnTitle;

class Solution {

    public String convertToTitle(int columnNumber) {
		var strBuilder = new StringBuilder();

		while (columnNumber-- > 0) {
			strBuilder.append((char)('A' + columnNumber % 26));
			columnNumber /= 26;
		}

		return strBuilder.reverse().toString();
	}
}
