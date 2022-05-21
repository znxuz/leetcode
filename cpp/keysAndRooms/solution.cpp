// https://leetcode.com/problems/keys-and-rooms/

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
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
	return bfs(rooms);
    }

private:
    bool bfs(const std::vector<std::vector<int>>& rooms)
    {
	std::unordered_set<int> visited;
	std::queue<int> que;
	visited.insert(0);
	for (int key : rooms.front())
	    que.push(key);

	while (!que.empty()) {
	    int cur = que.front();
	    que.pop();
	    if (!visited.insert(cur).second)
		continue;
	    for (int key : rooms[cur])
		que.push(key);
	}

	return (visited.size() == rooms.size());
    }

    void dfs(const std::vector<std::vector<int>>& rooms, size_t idx,
	    std::unordered_set<size_t>& visited)
    {
	if (!visited.insert(idx).second || rooms[idx].empty())
	    return;

	for (auto i : rooms[idx])
	    dfs(rooms, i, visited);
    }
};

int main(int argc, char** argv)
{
}
