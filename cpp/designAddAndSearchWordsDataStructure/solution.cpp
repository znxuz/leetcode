// https://leetcode.com/problems/design-add-and-search-words-data-structure/

#include <algorithm>
#include <array>
#include <memory>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class WordDictionary
{
public:
    WordDictionary()
    {
	root = std::make_unique<trie>();
    }

    void addWord(string word)
    {
	root->insert(word);
    }

    bool search(string word)
    {
	return root->contains(word, 0);
    }

private:
    struct trie
    {
	std::array<std::unique_ptr<trie>, 26> children{};
	bool is_word = false;

	// time: O(n): n = s.size()
	void insert(const std::string& s)
	{
	    trie* cur = this;
	    for (char c : s) {
		auto& next = cur->children[c - 'a'];
		if (!next)
		    next = std::make_unique<trie>();
		cur = next.get();
	    }
	    cur->is_word = true;
	}

	// time: O(n * 26^3)
	bool contains(const std::string& s, size_t i)
	{
	    auto* cur = this;
	    while (i < s.size()) {
		if (s[i] == '.')
		    return std::any_of(begin(cur->children), end(cur->children),
			    [&s, i](const std::unique_ptr<trie>& child)
			    { return child && child->contains(s, i + 1); });

		const auto& next = cur->children[s[i++] - 'a'];
		if (!next)
		    return false;
		cur = next.get();
	    }

	    return cur->is_word;
	}
    };

    std::unique_ptr<trie> root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main(int argc, char** argv)
{
    WordDictionary dict;
    dict.addWord("bad");
    dict.addWord("dad");
    std::cout << dict.search("pad") << '\n'; // return False
    std::cout << dict.search("bad") << '\n'; // return True
    std::cout << dict.search(".ad") << '\n'; // return True
    std::cout << dict.search("b..") << '\n'; // return True
}
