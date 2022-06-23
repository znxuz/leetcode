// https://leetcode.com/problems/univalued-binary-tree/

#include "helper.h"

using namespace std;
using namespace util;

/**
 * Definition for a binary tree node.
 * struct TreeNode 
 {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) 
 {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) 
 {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) 
 {}
 * };
 */
class Solution 
{
public:
    bool isUnivalTree(TreeNode* root) 
    {
	return rec(root);
    }

private:
    bool iter(const TreeNode* root)
    {
	auto stk = std::stack<const TreeNode*>();
	stk.push(root);
	int unival = root->val;
	while (!stk.empty()) {
	    const auto* node = stk.top();
	    stk.pop();
	    if (!node)
		continue;
	    if (unival != node->val)
		return false;
	    stk.push(node->left);
	    stk.push(node->right);
	}

	return true;
    }

    bool rec(const TreeNode* root)
    {
	if (!root || (!root->left && !root->right))
	    return true;

	if (root->left && (root->val != root->left->val || !rec(root->left)))
	    return false;
	if (root->right && (root->val != root->right->val || !rec(root->right)))
	    return false;
	return true;
    }
};

int main(int argc, char** argv)
{
}
