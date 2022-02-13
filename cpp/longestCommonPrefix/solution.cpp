#include <algorithm>
#include <cstdint>
#include <ios>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution
{
    public:

        // time complexity: O(n logn)
        // space complexity: O(n)
        string longestCommonPrefixSort(vector<string>& strs)
        {
            sort(strs.begin(), strs.end());
            string res;

            string begin = strs[0];
            string end = strs[strs.size() - 1];
            for (int i = 0; i < strs[0].size(); ++i) {
                if (begin[i] != end[i])
                    break;
                res.push_back(begin[i]);
            }

            return res;
        }

        string longestCommonPrefix(vector<string>& strs)
        {
            string res;
            int min = INT32_MAX;
            for_each(strs.begin(), strs.end(), [min] (string s) { std::min(min, static_cast<int>(s.size())); });
            for (int j = 0; j < strs[0].size(); ++j) {
                char c = strs[0][j];
                for (int i = 1; i < strs.size(); ++i) {
                    if (strs[i][j] != c)
                        return res;
                }
                res += c;
            }

            return res;
        }
};

int main(int argc, char** argv)
{
}
