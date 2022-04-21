// https://leetcode.com/problems/design-hashset/

#include <array>
#include <list>
#include <iostream>
#include <vector>

#include "helper.h"
#include "TreeNode.h"

using namespace std;
using namespace util;

class MyHashSet
{
public:
	void add(int key)
	{
		if (!contains(key))
			bucket[hash_(key)].push_back(key);
	}

	void remove(int key)
	{
		if (!contains(key))
			return;

		auto hash = hash_(key);
		if (bucket[hash].size() == 1)
			bucket[hash].pop_back();
		else
			bucket[hash].erase(locate(hash, key));
	}

	bool contains(int key)
	{
		auto hash = hash_(key);
		return locate(hash, key) != bucket[hash].end();
	}

private:
	constexpr static size_t size = 769;
	std::array<std::list<int>, size> bucket;

	size_t hash_(int key)
	{
		return static_cast<size_t>(key) % size;
	}

	std::list<int>::iterator locate(size_t hash, int key)
	{
		return std::find(begin(bucket[hash]), end(bucket[hash]), key);
	}
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main(int argc, char** argv)
{
}
