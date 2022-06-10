// https://leetcode.com/problems/shortest-word-distance-ii/

#include <limits>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

// time:
//  ctor: O(n)
//  query: O(n)
// space: O(n)
class WordDistance 
{
public:
    WordDistance(vector<string>& words) 
    {
	for (size_t i = 0; i < words.size(); ++i)
	    indices_map[words[i]].push_back(i);
    }

    int shortest(string word1, string word2) 
    {
	const auto& indices1 = indices_map[word1];
	const auto& indices2 = indices_map[word2];
	int min = std::numeric_limits<int>::max();
	for (size_t i = 0, j = 0; i < indices1.size() && j < indices2.size();) {
	    min = std::min(min, std::abs(indices1[i] - indices2[j]));
	    indices1[i] <= indices2[j] ? ++i : ++j;
	}

	return min;
    }

private:
    std::unordered_map<std::string, std::vector<int>> indices_map;
};

// time:
//  ctor: O(n)
//  query: O(n^2)
// space: O(n)
class WordDistanceBruteforce 
{
public:
    WordDistanceBruteforce(vector<string>& words) 


    {
	for (size_t i = 0; i < words.size(); ++i)
	    indices_map[words[i]].push_back(i);
    }

    int shortest(string word1, string word2) 


    {
	const auto& indices1 = indices_map[word1];
	const auto& indices2 = indices_map[word2];
	int min = std::numeric_limits<int>::max();
	for (auto i1 : indices1) 

	{
	    for (auto i2 : indices2)
		min = std::min(min, std::abs(i1 - i2));
	}

	return static_cast<int>(min);
    }

private:
    std::unordered_map<std::string, std::vector<int>> indices_map;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */

int main(int argc, char** argv)
{
}
