// https://leetcode.com/problems/cousins-in-binary-tree/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    bool isCousins(TreeNode* root, int x, int y) 
    {
	return bfs_iter(root, x, y);
    }

private:
    bool bfs_iter(const TreeNode* root, int x, int y)
    {
	auto que = std::queue<std::pair<const TreeNode*, const TreeNode*>>();
	que.emplace(root, root);
	while (!que.empty()) {
	    auto sz = que.size();
	    const auto* parent_of_one = static_cast<TreeNode*>(nullptr);
	    while (sz--) {
		auto [parent, node] = que.front();
		que.pop();
		if (!node)
		    continue;
		if (node->val == x || node->val == y) {
		    if (!parent_of_one)
			parent_of_one = parent;
		    else if (parent == parent_of_one)
			return false;
		    else
			return true;
		}
		que.emplace(node, node->left);
		que.emplace(node, node->right);
	    }
	}

	return false;
    }
};

int main(int argc, char** argv)
{
}
