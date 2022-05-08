// https://leetcode.com/problems/flatten-nested-list-iterator/

#include <stack>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

 class NestedInteger
{
     public:
	 // Return true if this NestedInteger holds a single integer, rather than a nested list.
	 bool isInteger() const;

	 // Return the single integer that this NestedInteger holds, if it holds a single integer
	 // The result is undefined if this NestedInteger holds a nested list
	 int getInteger() const;

	 // Return the nested list that this NestedInteger holds, if it holds a nested list
	 // The result is undefined if this NestedInteger holds a single integer
	 const vector<NestedInteger> &getList() const;
 };

class NestedIterator
{
    public:
	NestedIterator(vector<NestedInteger> &nestedList)
	{
	    for (size_t i = nestedList.size(); i-- > 0;)
		stk.push(&nestedList[i]);
	}

	// O(n)
	int next()
	{
	    hasNext();

	    auto nested = stk.top();
	    stk.pop();
	    return nested->getInteger();
	}

	// O(n)
	bool hasNext()
	{
	    while (!stk.empty()) {
		if (stk.top()->isInteger())
		    return true;

		auto* nested = stk.top();
		stk.pop();
		auto& list = nested->getList();
		for (size_t i = list.size(); i-- > 0;)
		    stk.push(&list[i]);
	    }

	    return false;
	}

    private:
	std::stack<const NestedInteger*> stk;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main(int argc, char** argv)
{
}
