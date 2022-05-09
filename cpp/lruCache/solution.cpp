// https://leetcode.com/problems/lru-cache/

#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class LRUCache
{
    public:
	LRUCache(unsigned capacity)
	{
	    head = tail = nullptr;
	    this->size = 0;
	    this->capacity = capacity;
	}

	int get(int key)
	{
	    if (!mp.count(key))
		return -1;

	    auto* n = mp[key];
	    promote(&head, &tail, n);

	    return n->val;
	}

	void put(int key, int val)
	{
	    if (mp.count(key)) {
		auto* n = mp[key];
		n->val = val;
		promote(&head, &tail, n);
		return;
	    }

	    auto* n = new node(key, val);
	    mp[key] = n;
	    append(&head, &tail, n);
	    if (size < capacity) {
		++size;
		return;
	    }

	    auto* new_head = head->next;
	    new_head->prev = nullptr;
	    mp.erase(head->key);
	    delete head;
	    head = new_head;
	}

    private:
	struct node
	{
	    int key;
	    int val;
	    node* prev;
	    node* next;

	    node(int k, int v, node* p, node* n) : key(k), val(v), prev(p), next(n)
	    {}
	    node(int k, int v) : node(k, v, nullptr, nullptr)
	    {}
	};

	void append(node** head, node** tail, node* n)
	{
	    if (!*head) {
		*head = *tail = n;
		return;
	    }

	    n->prev = *tail;
	    *tail = (*tail)->next = n;
	}

	void promote(node** head, node** tail, node* n)
	{
	    if (*tail == n)
		return;
	    if (*head == n)
		*head = n->next;

	    auto* prev = n->prev;
	    auto* next = n->next;
	    if (prev)
		prev->next = next;
	    next->prev = prev;
	    n->prev = *tail;
	    n->next = nullptr;
	    *tail = (*tail)->next = n;
	}

	node* head;
	node* tail;
	unsigned size;
	unsigned capacity;
	std::unordered_map<int, node*> mp;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(int argc, char** argv)
{
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    std::cout << "get 1: " << cache.get(1) << '\n';
    std::cout << "get 2: " << cache.get(2) << '\n';
    cache.put(3, 3);
    std::cout << "get 3: " << cache.get(3) << '\n';
}
