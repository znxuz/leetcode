// https://leetcode.com/problems/unique-word-abbreviation/

#include "helper.h"

using namespace std;
using namespace util;

class ValidWordAbbr 
{
public:
    ValidWordAbbr(vector<string>& dict) 
    {
	for (const auto& s : dict)
	    abbrs[get_abbr(s)].push_back(s);
    }

    bool isUnique(string word) 
    {
	auto abbr = get_abbr(word);
	return !abbrs.count(abbr)
	    || std::all_of(begin(abbrs[abbr]), end(abbrs[abbr]),
		    [&word](const std::string& elem) { return elem == word; });
    }

private:
    std::unordered_map<std::string, std::vector<std::string>> abbrs;

    std::string get_abbr(const std::string& word)
    {
	auto abbr = std::string();
	auto between_len = word.size() - 2;
	if (!between_len || between_len >= word.size())
	    return word;
	return abbr.append(1, word.front())
	    .append(std::to_string(between_len))
	    .append(1, word.back());
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */

void test(std::vector<std::string> vec)
{
    ValidWordAbbr v(vec);
    std::cout << v.isUnique("cake") << '\n';
}

int main(int argc, char** argv)
{
    test({"deer","door","cake","card"});
}
