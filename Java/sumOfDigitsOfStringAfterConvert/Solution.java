// https://leetcode.com/problems/sum-of-digits-of-string-after-convert/

package sumOfDigitsOfStringAfterConvert;

class Solution {

    // time complexity: O(n)
    // space complexity: O(1)
    public int getLucky(String s, int k) {
        int num = 0;
        for (char c : s.toCharArray()) {
            int cur = c - 'a' + 1;
            num += cur / 10 + cur % 10;
        }
        while (k-- > 1)
            num = digitSum(num);

        return num;
    }

    private int digitSum(int num) {
        if (num < 0)
            return 0;
        if (num < 10)
            return num;

        return digitSum(num / 10) + num % 10;
    }

}
