// https://leetcode.com/problems/implement-queue-using-stacks/

#include <iterator>
#include <stack>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class MyQueue
{
public:
	void push(int x)
	{
		while (!main.empty())
			helper.push(main.top()), main.pop();
		main.push(x);
		while (!helper.empty())
			main.push(helper.top()), helper.pop();
	}

	int pop()
	{
		int ret = main.top();
		main.pop();
		return ret;
	}

	int peek()
	{
		return main.top();
	}

	bool empty()
	{
		return main.empty();
	}

private:
	stack<int> main;
	stack<int> helper;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main(int argc, char** argv)
{
}
