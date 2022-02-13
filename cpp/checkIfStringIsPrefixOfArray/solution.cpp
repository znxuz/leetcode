#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
        bool isPrefixString(string s, vector<string>& words)
        {
            int i = 0;
            for (int j = 0; j < words.size() && i < s.size(); ++j) {
                for (auto& c : words[j]) {
                    if (i == s.length() || s[i] != c)
                        return false;
                    i++;
                }
            }
            return i == s.size();
        }
};

int main(int argc, char** argv)
{
}
