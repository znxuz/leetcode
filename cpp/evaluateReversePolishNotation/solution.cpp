// https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include <limits>
#include <functional>
#include <unordered_map>
#include <cstdlib>
#include <stack>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    int evalRPN(vector<string>& tokens)
    {
	return via_stack(tokens);
    }

private:
    int via_stack(const std::vector<std::string>& tokens)
    {
	if (tokens.empty())
	    return 0;

	std::unordered_map<std::string, std::function<int(int, int)>> operations {
	    {"+", [](int a, int b) { return a + b; }},
		{"-", [](int a, int b) { return a - b; }},
		{"*", [](int a, int b) { return a * b; }},
		{"/", [](int a, int b) { return a / b; }}
	};
	std::stack<int> stk;
	for (const auto& t : tokens) {
	    if (!operations.count(t)) {
		stk.push(std::atoi(t.c_str()));
		continue;
	    }

	    int op_right = stk.top();
	    stk.pop();
	    int op_left = stk.top();
	    stk.pop();
	    stk.push(operations[t](op_left, op_right));
	}

	return stk.top();

    }
};

int main(int argc, char** argv)
{
}
