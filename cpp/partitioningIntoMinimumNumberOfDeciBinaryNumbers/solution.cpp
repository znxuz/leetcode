// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

#include <algorithm>

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    int minPartitions(string n) 
    {
	return *std::max_element(begin(n), end(n)) - '0';
    }
};

int main(int argc, char** argv)
{
}
