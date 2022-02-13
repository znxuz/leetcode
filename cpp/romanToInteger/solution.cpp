#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
    public:
        // time complexity: O(n)
        // space complexity: O(1)
        int romanToInt(string s)
        {
            // unordered_map<char, int> map {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
            int map[26];
            map['I' - 'A'] = 1;
            map['V' - 'A'] = 5;
            map['X' - 'A'] = 10;
            map['L' - 'A'] = 50;
            map['C' - 'A'] = 100;
            map['D' - 'A'] = 500;
            map['M' - 'A'] = 1000;

            int res = 0;
            int prev = 0;
            for (int i = 0; i < s.size(); ++i) {
                int cur = map[s[i] - 'A'];
                if (i > 0 && (prev == cur / 5 || prev == cur / 10))
                    res -= prev * 2;
                res += cur;
                prev = cur;
            }

            return res;
        }
};

int main(int argc, char** argv)
{
    std::cout << Solution().romanToInt("MCMXCIV");
}
