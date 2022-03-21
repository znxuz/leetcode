// https://leetcode.com/problems/implement-stack-using-queues/

#include <iterator>
#include <queue>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

// one queue
class MyStack
{
public:
	// time: O(n)
    void push(int x)
	{
		auto size = q.size();
		q.push(x);
		for (size_t i = 0; i < size; ++i)
			q.push(q.front()), q.pop();
    }
    
    int pop()
	{
		int tmp = q.front();
		q.pop();
		return tmp;
    }
    
    int top()
	{
		return q.front();
    }
    
    bool empty()
	{
		return q.empty();
    }

private:
	queue<int> q;
};

class MyStackTwoQueues
{
	public:
		// time: O(n)
		void push(int x)
		{
			auto& empty = (q1.empty() ? q1 : q2);
			auto& occupied = (q1.empty() ? q2 : q1);
			empty.push(x);
			while (!occupied.empty())
				empty.push(occupied.front()), occupied.pop();
		}

		// time: O(1)
		int pop()
		{
			auto& occupied = (q1.empty() ? q2 : q1);
			int tmp = occupied.front();
			occupied.pop();
			return tmp;
		}

		// time: O(1)
		int top()
		{
			auto& occupied = (q1.empty() ? q2 : q1);
			return occupied.front();
		}

		// time: O(1)
		bool empty()
		{
			return (q1.empty() ? q2 : q1).empty();
		}

	private:
		queue<int> q1;
		queue<int> q2;
};

int main(int argc, char** argv)
{
}
