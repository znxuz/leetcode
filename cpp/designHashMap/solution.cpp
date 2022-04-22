// https://leetcode.com/problems/design-hashmap/

#include <algorithm>
#include <array>
#include <list>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class MyHashMap
{
public:
	void put(int key, int val)
	{
		auto hash = hash_(key);
		auto it = key_iter(hash, key);
		if (it == table[hash].end())
			table[hash].emplace_back(key, val);
		else
			it->second = val;
	}

	int get(int key)
	{
		auto hash = hash_(key);
		auto it = key_iter(hash, key);
		return (it == table[hash].end() ? -1 : it->second);
	}

	void remove(int key)
	{
		auto hash = hash_(key);
		auto it = key_iter(hash, key);
		if (it != table[hash].end())
			table[hash].erase(it);
	}

private:
	constexpr static size_t size = 2069;
	std::array<std::list<std::pair<int, int>>, size> table;

	size_t hash_(int key)
	{
		return static_cast<size_t>(key) % size;
	}

	std::list<std::pair<int, int>>::iterator key_iter(size_t hash, int key)
	{
		auto it = table[hash].begin();
		while (it != table[hash].end()) {
			if (it->first == key)
				return it;
			++it;
		}
		return it;
	}
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main(int argc, char** argv)
{
}
