// https://leetcode.com/problems/1-bit-and-2-bit-characters/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
    public:
	bool isOneBitCharacter(vector<int>& bits)
	{
	    unsigned one_cnt = 0;
	    size_t i = bits.size() - 1;
	    while (i < bits.size() && !bits[i])
		--i;
	    if (bits.size() - i > 2)
		return true;
	    while (i < bits.size() && bits[i--])
		++one_cnt;
	    return !(one_cnt % 2);
	}
};

int main(int argc, char** argv)
{
}
