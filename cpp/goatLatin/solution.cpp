// https://leetcode.com/problems/goat-latin/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    string toGoatLatin(string sentence)
    {
	std::string res;
	std::string buf;
	size_t idx = 0;
	for (size_t i = 0; i < sentence.size() || !buf.empty(); ++i) {
	    if (i < sentence.size() && sentence[i] != ' ') {
		buf.push_back(sentence[i]);
	    } else if (!buf.empty()) {
		res.append(goat_word(std::move(buf), ++idx)).append(1, ' ');
		buf.clear();
	    }
	}
	res.pop_back();

	return res;
    }

private:
    std::string goat_word(std::string word, size_t idx)
    {
	if (!is_vowel(std::tolower(word.front()))) {
	    word.push_back(word.front());
	    word.erase(word.begin());
	}
	return word.append("ma").append(idx, 'a');
    }

    bool is_vowel(int c)
    {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};

int main(int argc, char** argv)
{
}
