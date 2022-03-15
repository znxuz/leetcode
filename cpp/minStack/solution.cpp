#include <stack>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// two stack track min
// time: O(n)
// space: O(2n) = O(n)
class MinStack
{
	public:
		MinStack()
		{
		}

		void push(int val)
		{
			stk.push(val);
			if (min.empty() || val <= min.top())
				min.push(val);
		}

		void pop()
		{
			if (!min.empty() && min.top() == stk.top())
				min.pop();
			stk.pop();
		}

		int top()
		{
			return stk.top();
		}

		int getMin()
		{
			return min.top();
		}

	private:
		std::stack<int> stk;
		std::stack<int> min;
};

// pair for storing min with each elem
// time: O(n)
// space: O(n)
class MinStackPair
{
	public:
		MinStackPair()
		{
		}

		void push(int val)
		{
			auto pair = std::make_pair(val, val);
			if (!stk.empty())
				pair.second = std::min(val, stk.back().second);
			stk.push_back(pair);
		}

		void pop()
		{
			stk.pop_back();
		}

		int top()
		{
			return stk.back().first;
		}

		int getMin()
		{
			return stk.back().second;
		}

	private:
		std::vector<std::pair<int, int>> stk;
};

int main(int argc, char** argv)
{
}
