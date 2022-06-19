// https://leetcode.com/problems/search-suggestions-system/

#include <memory>

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string search_word) 
    {
	auto tr = trie();
	for (const auto& s : products)
	    tr.add_word(s);

	auto res = std::vector<std::vector<std::string>>(search_word.size());
	for (size_t i = 0; i < search_word.size(); ++i)
	    res[i] = tr.prefix_matches(search_word.substr(0, i + 1));
	return res;
    }

private:
    class trie
    {
    public:
	void add_word(const std::string& word)
	{
	    auto* tr = this;
	    for (char c : word) {
		if (!(*tr)[c - 'a'])
		    (*tr)[c - 'a'] = std::make_unique<trie>();
		tr = (*tr)[c - 'a'].get();
	    }
	    tr->is_word = true;
	}

	std::vector<std::string> prefix_matches(const std::string& prefix)
	{
	    auto* tr = this;
	    for (char c : prefix) {
		if (!(*tr)[c - 'a'])
		    return {};
		tr = (*tr)[c - 'a'].get();
	    }

	    auto res = std::vector<std::string>();
	    tr->pop_words(res, 3, prefix);
	    return res;
	}

	void pop_words(std::vector<std::string>& res, size_t cnt, std::string word = "")
	{
	    if (res.size() >= cnt)
		return;

	    auto* tr = this;
	    if (tr->is_word)
		res.push_back(word);
	    for (size_t i = 0; i < tr->children.size() && res.size() < cnt; ++i) {
		if ((*tr)[i])
		    (*tr)[i]->pop_words(res, cnt, word + static_cast<char>(i + 'a'));
	    }
	}

	std::unique_ptr<trie>& operator[](size_t i)
	{
	    return children[i];
	}

    private:
	std::array<std::unique_ptr<trie>, 26> children;
	bool is_word = false;
    };
};

auto test(std::vector<std::string> products, std::string search_word)
{
    return Solution().suggestedProducts(products, search_word);
}

int main(int argc, char** argv)
{
    auto res = test({"mobile","mouse","moneypot","monitor","mousepad"}, "mouse");
    for (const auto& list : res)
	print_container(list);
}
