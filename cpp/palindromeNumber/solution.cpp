#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        // time complexity: O(log_10(n))
        // space complexity: O(n)
        bool isPalindrome(int x) {
            if (x < 0 || (x % 10 == 0 && x != 0))
                return false;

            int y = 0;
            while (y < x) {
                y = y * 10 + x % 10;
                x /= 10;
            }
            return x == y || y / 10 == x;
        }

        // time complexity: O(n)
        // space complexity: O(n)
        bool isPalindromeString(int x) {
            string s = to_string(x);
            string::iterator left = s.begin();
            string::iterator right = s.end() - 1;
            while (left < right) {
                if (*left != *right)
                    return false;
                left++;
                right--;
            }
            return true;
        }
};

int main(int argc, char** argv)
{
    cout << boolalpha << Solution().isPalindrome(121) << endl;
    cout << boolalpha << Solution().isPalindrome(-121) << endl;
}
