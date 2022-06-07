// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

#include <iostream>
#include <vector>

#include "helper.h"
#include "TreeNode.h"

using namespace std;
using namespace util;

class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
	return rec(root, p, q);
    }

private:
    TreeNode* rec(TreeNode* root, TreeNode* p, TreeNode* q)
    {
	if (!root || root == p || root == q)
	    return root;

	TreeNode* left = rec(root->left, p, q);
	TreeNode* right = rec(root->right, p, q);
	if (!left || !right)
	    return (!left ? right : left);
	return root;
    }
};

int main(int argc, char** argv)
{
}
