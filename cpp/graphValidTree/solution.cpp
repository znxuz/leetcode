// https://leetcode.com/problems/graph-valid-tree/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    // every node is connected - only one tree
    // no cycles
    bool validTree(int n, vector<vector<int>>& edges) 
    {
	return iter_dfs(n, edges);
    }

private:
    bool iter_dfs(size_t n, const std::vector<std::vector<int>>& edges)
    {
	if (edges.size() + 1 != n)
	    return false;

	// IIFE
	auto adj_list = [&edges]() {
	    auto adj_list = std::vector<std::vector<int>>(edges.size() + 1);
	    for (const auto& e : edges) {
		adj_list[e.front()].push_back(e.back());
		adj_list[e.back()].push_back(e.front());
	    }
	    return adj_list;
	}();
	auto seen = std::unordered_set<int>();
	auto stk = std::stack<int>();
	seen.insert(0);
	stk.push(0);
	while (!stk.empty()) {
	    auto node = stk.top();
	    stk.pop();
	    for (auto neighbor : adj_list[node]) {
		if (!seen.insert(neighbor).second)
		    continue;
		stk.push(neighbor);
	    }
	}

	return seen.size() == n;
    }
};

int main(int argc, char** argv)
{
}
