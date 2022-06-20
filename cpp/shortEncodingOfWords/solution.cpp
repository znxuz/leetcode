// https://leetcode.com/problems/short-encoding-of-words/

#include <algorithm>

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    int minimumLengthEncoding(vector<string>& words) 
    {
	std::sort(begin(words), end(words),
		[](const std::string& lhs, const std::string& rhs) {
		    return lhs.size() > rhs.size();
		});
	auto tr = trie();
	size_t cnt = 0;
	for (const auto& word : words) {
	    // FIXME takes reverse iterators
	    if (!tr.starts_with(word.crbegin(), word.crend()))
		cnt += word.size() + 1;
	    tr.add_word(word.crbegin(), word.crend());
	}

	return cnt;
    }

private:
    class trie
    {
    public:
	void add_word(std::string::const_reverse_iterator begin,
		const std::string::const_reverse_iterator end)
	{
	    auto* tr = this;
	    while (begin != end) {
		auto c = *begin++;
		auto& cur = tr->children[c - 'a'];
		if (!cur)
		    cur = std::make_unique<trie>();
		tr = cur.get();
	    }
	    tr->is_word = true;
	}

	bool starts_with(std::string::const_reverse_iterator begin,
		const std::string::const_reverse_iterator end)
	{
	    const auto* tr = this;
	    while (begin != end) {
		auto c = *begin++;
		auto& cur = tr->children[c - 'a'];
		if (!cur)
		    return false;
		tr = cur.get();
	    }
	    return true;
	}

	void print_all(std::string prev = "")
	{
	    auto* tr = this;
	    if (tr->is_word)
		std::cout << prev << '\n';
	    for (size_t i = 0; i < tr->children.size(); ++i) {
		if (tr->children[i])
		    tr->children[i]->print_all(prev + static_cast<char>(i + 'a'));
	    }
	}

    private:
	std::array<std::unique_ptr<trie>, 26> children;
	bool is_word = false;
    };
};

int main(int argc, char** argv)
{
    auto arr = std::vector<std::string>{"time", "me", "bell"};
    std::cout << Solution().minimumLengthEncoding(arr) << '\n';
}
