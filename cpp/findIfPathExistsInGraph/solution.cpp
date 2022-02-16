// https://leetcode.com/problems/find-if-path-exists-in-graph/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
	public:
		// DFS iter
		// time complexity: O(n * logn)
		// space complexity: O(n^2)
		bool validPath(int n, vector<vector<int>>& edges, int src, int dest)
		{
			if (src == dest)
				return true;

			unordered_map<int, vector<int>> map;
			for (auto& e : edges) {
				map[e[0]].push_back(e[1]);
				map[e[1]].push_back(e[0]);
			}
			stack<int> st;
			vector<bool> visited(n);
			st.push(src);
			while (!st.empty()) {
				int cur = st.top();
				visited[cur] = true;
				st.pop();
				vector<int> vertices = map[cur];
				if (find(begin(vertices), end(vertices), dest) != end(vertices))
					return true;
				for (auto v : vertices) {
					if (!visited[v])
						st.push(v);
				}
			}
			return false;
		}
};
int main(int argc, char** argv)
{
}
