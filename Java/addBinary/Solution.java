// https://leetcode.com/problems/add-binary/

package addBinary;

class Solution {

    public String addBinary(String a, String b) {
		int aIndex = a.length() - 1;
		int bIndex = b.length() - 1;
		boolean carry = false;
		var strbuilder = new StringBuilder();
		int sum;

		while (aIndex >= 0 || bIndex >= 0) {
			sum = carry ? 1 : 0;
			if (aIndex < 0) {
				sum += b.charAt(bIndex) - '0';
			} else if (bIndex < 0) {
				sum += a.charAt(aIndex) - '0';
			} else {
				sum += (a.charAt(aIndex) - '0') + (b.charAt(bIndex) - '0');
			}
			carry = sum > 1 ? true : false;
			strbuilder.append((char)(sum % 2 + '0'));
			aIndex--;
			bIndex--;
		}
		if (carry)
			strbuilder.append('1');

		return strbuilder.reverse().toString();
	}

	// invalid
    public String addBinaryInvalid(String a, String b) {
		return Integer.toBinaryString(Integer.parseInt(a, 2) + Integer.parseInt(b, 2));
    }
}
