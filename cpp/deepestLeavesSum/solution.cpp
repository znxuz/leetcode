// https://leetcode.com/problems/deepest-leaves-sum/

#include <stack>
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
    int deepestLeavesSum(TreeNode* root)
    {
	return bfs(root);
    }

private:
    int bfs(const TreeNode* root)
    {
	std::queue<const TreeNode*> que;
	que.push(root);
	int sum = 0;
	while (!que.empty()) {
	    size_t size = que.size();
	    int lvl_sum = 0;
	    while (size-- > 0) {
		const TreeNode* node = que.front();
		que.pop();
		if (!node)
		    continue;
		lvl_sum += node->val;
		que.push(node->left);
		que.push(node->right);
	    }
	    if (lvl_sum)
		sum = lvl_sum;
	}

	return sum;
    }
};

int main(int argc, char** argv)
{
}
