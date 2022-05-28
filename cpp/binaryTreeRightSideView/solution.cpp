// https://leetcode.com/problems/binary-tree-right-side-view/

#include <queue>
#include <iostream>
#include <vector>

#include "helper.h"
#include "TreeNode.h"

using namespace std;
using namespace util;

class Solution
{
public:
    vector<int> rightSideView(TreeNode* root)
    {
	std::vector<int> res;
	rec_dfs(root, 0, res);
	return res;
    }

private:
    void rec_dfs(const TreeNode* root, size_t lvl, std::vector<int>& res)
    {
	if (!root)
	    return;

	if (lvl == res.size())
	    res.push_back(root->val);

	++lvl;
	rec_dfs(root->right, lvl, res);
	rec_dfs(root->left, lvl, res);
    }

    std::vector<int> iter_bfs(const TreeNode* root)
    {
	std::vector<int> res;
	std::queue<const TreeNode*> que;
	que.push(root);
	while (!que.empty()) {
	    auto sz = que.size();
	    const TreeNode* last = nullptr;
	    while (sz--) {
		auto* node = que.front();
		que.pop();
		if (!node)
		    continue;
		que.push(node->left);
		que.push(node->right);
		last = node;
	    }
	    if (last)
		res.push_back(last->val);
	}

	return res;
    }
};

int main(int argc, char** argv)
{
}
