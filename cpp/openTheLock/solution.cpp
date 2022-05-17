// https://leetcode.com/problems/open-the-lock/

#include <array>
#include <queue>
#include <unordered_set>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    int openLock(vector<string>& deadends, string target)
    {
	return bfs(deadends, target);
    }

private:
    // time: O(10^4 * 4^2 + D)
    //	10 x 10 x 10 x 10 combinations in total
    //	loop at each iteration 2 times constructing 2 string combinations -> 4^2
    //	D = length of deadends
    int bfs(const std::vector<std::string>& deadends, const std::string& target)
    {
	std::unordered_set<std::string> deads(begin(deadends), end(deadends));
	std::unordered_set<std::string> tried;
	std::queue<std::pair<std::string, int>> que;

	std::string start = "0000";
	tried.insert(start);
	que.push(std::pair(start, 0));
	while (!que.empty()) {
	    auto [cmb, cnt] = que.front();
	    que.pop();
	    if (cmb == target)
		return cnt;
	    if (deads.count(cmb))
		continue;
	    for (size_t i = 0; i < cmb.size(); ++i) {
		char tmp = cmb[i];
		for (int d = -1; d <= 1; d += 2) {
		    cmb[i] += d;
		    if (cmb[i] < '0')
			cmb[i] = '9';
		    if (cmb[i] > '9')
			cmb[i] = '0';
		    if (tried.insert(cmb).second)
			que.push(std::pair(cmb, cnt + 1));
		    cmb[i] = tmp;
		}
	    }
	}

	return -1;
    }
};

int main(int argc, char** argv)
{
}
