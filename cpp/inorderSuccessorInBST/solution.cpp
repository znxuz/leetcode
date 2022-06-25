// https://leetcode.com/problems/inorder-successor-in-bst/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) 
    {
	return improved(root, p);
    }

private:
    // time: O(n), O(nlog(n)) when tree is balanced
    // space: O(1)
    TreeNode* improved(TreeNode* root, TreeNode* p)
    {
	TreeNode* successor = nullptr;
	while (root) {
	    if (root->val > p->val)
		successor = root, root = root->left;
	    else
		root = root->right;
	}

	return successor;
    }

    // time: O(n)
    // space: O(n)
    TreeNode* iter(TreeNode* root, TreeNode* p)
    {
	auto inorder = std::vector<TreeNode*>();
	auto stk = std::stack<TreeNode*>();
	auto iter = size_t(0);
	stk.push(root);
	while (!stk.empty()) {
	    auto node = stk.top();
	    stk.pop();
	    if (!node)
		continue;
	    if (stk.empty() || stk.top() != node->right) {
		stk.push(node->right);
		stk.push(node);
		stk.push(node->left);
		continue;
	    }
	    inorder.push_back(node);
	    if (node == p)
		iter = inorder.size() - 1;
	    else if (p->val < node->val)
		break;
	}

	return (iter + 1 == inorder.size() ? nullptr : inorder[++iter]);
    }
};

int main(int argc, char** argv)
{
}
