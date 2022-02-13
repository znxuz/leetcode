#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
    public:
        // time complexity: O(n)
        // space complexity: O(1)
        bool isValid(string s)
        {
            stack<char> st;
            for (auto c : s) {
                if (c == '(' || c == '[' || c == '{')
                    st.push(c);
                else if (!st.empty() && (st.top() == c - 2 || st.top() == c - 1))
                    st.pop();
                else
                    return false;
            }
            return st.empty();
        }
};

int main(int argc, char** argv)
{
}
