// https://leetcode.com/problems/implement-trie-prefix-tree/

#include <algorithm>
#include <memory>
#include <array>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Trie
{
public:
    Trie()
    {}

    void insert(string word)
    {
	auto* trie = this;
	for (char c : word) {
	    auto& next = trie->children[c - 'a'];
	    if (!next)
		next = std::make_unique<Trie>();
	    trie = next.get();
	}
	trie->is_end = true;
    }

    bool search(string word)
    {
	const auto* trie = this;
	for (char c : word) {
	    auto& next = trie->children[c - 'a'];
	    if (!next)
		return false;
	    trie = next.get();
	}

	return trie->is_end;
    }

    bool startsWith(string prefix)
    {
	const auto* trie = this;
	for (char c : prefix) {
	    auto& next = trie->children[c - 'a'];
	    if (!next)
		return false;
	    trie = next.get();
	}
	return true;
    }

private:
    std::array<std::unique_ptr<Trie>, 26> children{};
    bool is_end = false;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(int argc, char** argv)
{
    Trie trie;
    trie.insert("apple");
    std::cout << trie.search("apple") << '\n';
    std::cout << trie.search("app") << '\n';
    std::cout << trie.startsWith("app") << '\n';
    trie.insert("app");
    std::cout << trie.search("app") << '\n';
}
