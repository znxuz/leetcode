// https://leetcode.com/problems/greatest-common-divisor-of-strings/

package greatestCommonDivisorOfStrings;

class Solution {

	// algorithm:
	// 	begins with the shortest string
	// 	get substring by setting the range via len / i: inorder to get
	// 	the longest common divisor first, rather than the shortest, it
	// 	if replace returns empty string for both, return the substring
    public String gcdOfStrings(String str1, String str2) {
        String shortest = str1.length() < str2.length() ? str1 : str2;
		int len = shortest.length();
        for (int i = 1; i <= len; ++i) {
            if (len % i != 0)
				continue;
            String sub = shortest.substring(0, len / i);
            if (str1.replace(sub, "").isEmpty() && str2.replace(sub, "").isEmpty()) {
                return sub;
            }
        }
        return "";
    }

    public String gcdOfStringsEuclidean(String str1, String str2) {
        if (str1.length() < str2.length()) {
            return gcdOfStringsEuclidean(str2, str1); 
        } else if (!str1.startsWith(str2)) {
            return ""; 
        } else if (str2.isEmpty()) {
            return str1;
        } else {
            return gcdOfStringsEuclidean(str1.substring(str2.length()), str2); 
        }
    }

}
