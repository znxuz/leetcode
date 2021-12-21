// https://leetcode.com/problems/remove-vowels-from-a-string/

package removeVowelsFromString;

class Solution {

    public String removeVowels(String s) {
		return s.replaceAll("[aeiou]", "");
    }
}
