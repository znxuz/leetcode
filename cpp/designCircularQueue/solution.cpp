// https://leetcode.com/problems/design-circular-queue/

#include <limits>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class MyCircularQueue
{
public:
    MyCircularQueue(size_t k) : capacity(k), size(0), front(0),
    back(std::numeric_limits<size_t>::max())
    {
	que.resize(capacity);
    }

    bool enQueue(int val)
    {
	if (size == capacity)
	    return false;

	back = ++back % capacity;
	que[back] = val;
	++size;

	return true;
    }

    bool deQueue()
    {
	if (isEmpty())
	    return false;

	front = ++front % capacity;
	--size;
	return true;
    }

    inline int Front()
    {
	return (isEmpty() ? -1 : que[front]);
    }

    inline int Rear()
    {
	return (isEmpty() ? -1 : que[back]);
    }

    inline bool isEmpty()
    {
	return !size;
    }

    inline bool isFull()
    {
	return size == capacity;
    }

private:
    std::vector<int> que;
    size_t capacity;
    size_t size;
    size_t front;
    size_t back;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main(int argc, char** argv)
{
}
