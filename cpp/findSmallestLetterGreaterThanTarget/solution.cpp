// https://leetcode.com/problems/find-smallest-letter-greater-than-target/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    char nextGreatestLetter(vector<char>& letters, char target)
    {
	return binary_search(letters, target);
    }

private:
    // post-processing binary search
    // time: O(n)
    // space: O(1)
    char binary_search(const std::vector<char>& letters, char target)
    {
	size_t lo = 0;
	size_t hi = letters.size();
	while (lo < hi) {
	    size_t md = lo + (hi - lo) / 2;
	    if (letters[md] <= target)
		lo = md + 1;
	    else
		hi = md;
	}
	return letters[lo % letters.size()];
    }

    // time: O(n)
    // space: O(1)
    char linear(const std::vector<char>& letters, char target)
    {
	for (char c : letters) {
	    if (c > target)
		return c;
	}
	return letters.front();
    }
};

int main(int argc, char** argv)
{
}
