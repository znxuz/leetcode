// https://leetcode.com/problems/three-divisors/

package threeDivisors;

class Solution {

    public boolean isThree(int n) {
        int divs = 2;
        for (int i = 2; divs <= 3 && i <= n / 2; ++i) {
            divs += (n % i == 0 ? 1 : 0);
        }
        return divs == 3;
    }

}
