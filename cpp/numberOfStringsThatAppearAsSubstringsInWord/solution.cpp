// https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
        // time complexity: O(n * m): n for word.length(), m for patterns.length
        // space complexity: O(1)
        int numOfStrings(vector<string>& patterns, string word)
        {
            int cnt = 0;
            int n = word.size();
            for (auto& p : patterns) {
                int m = p.size();
                for (int i = 0; i < n - m + 1; ++i) {
                    int j = 0;
                    while (j < p.size() && p[j] == word[i + j])
                        j++;
                    if (j == p.size()) {
                        cnt++;
                        break;
                    }
                }
            }

            return cnt;
        }

        // time complexity: O(n * m): n for word.length(), m for patterns.length
        // space complexity: O(1)
        int numOfStringsBuiltIn(vector<string>& patterns, string word)
        {
            int cnt = 0;
            for (auto& p : patterns) {
                if (word.find(p) != string::npos)
                    cnt++;
            }

            return cnt;
        }
};

int main(int argc, char** argv)
{
}
