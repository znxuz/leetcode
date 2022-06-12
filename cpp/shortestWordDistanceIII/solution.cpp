// https://leetcode.com/problems/shortest-word-distance-iii/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) 
    {
	return swap_indices(words, word1, word2);
    }

private:
    // time: O(n)
    // space: O(1)
    int swap_indices(const std::vector<std::string>& words,
	    const std::string& word1, const std::string& word2)
    {
	size_t min = std::numeric_limits<decltype(min)>::max();
	size_t idx1 = std::numeric_limits<decltype(idx1)>::max();
	size_t idx2 = std::numeric_limits<decltype(idx2)>::max();
	bool same_word = (word1 == word2);
	for (size_t i = 0; i < words.size(); ++i) {
	    if (words[i] == word1) {
		idx1 = i;
		if (same_word)
		    std::swap(idx1, idx2);
	    } else if (words[i] == word2) {
		idx2 = i;
	    }

	    if (idx1 != idx2)
		min = std::min(min, std::max(idx1, idx2) - std::min(idx1, idx2));
	}
	return static_cast<int>(min);
    }

    int indices_map(const std::vector<std::string>& words,
	    const std::string& word1, const std::string& word2)
    {
	std::unordered_map<std::string, std::vector<size_t>> indices_mp;
	for (size_t i = 0; i < words.size(); ++i)
	    indices_mp[words[i]].push_back(i);

	const auto& indices1 = indices_mp[word1];
	const auto& indices2 = indices_mp[word2];
	int min = std::numeric_limits<int>::max();
	for (size_t i = 0, j = 0; i < indices1.size() && j < indices2.size();) {
	    auto idx1 = indices1[i];
	    auto idx2 = indices2[j];
	    if (idx1 != idx2)
		min = std::min(min, static_cast<int>(std::max(idx1, idx2) - std::min(idx1, idx2)));
	    idx1 <= idx2 ? ++i : ++j;
	}

	return min;
    }
};

int main(int argc, char** argv)
{
}
