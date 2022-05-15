// https://leetcode.com/problems/binary-tree-upside-down/

#include <iostream>
#include <vector>

#include "helper.h"
#include "TreeNode.h"

using namespace std;
using namespace util;

class Solution
{
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root)
    {
	if (!root || (!root->left && !root->right))
	    return root;

	TreeNode* new_root = upsideDownBinaryTree(root->left);
	root->left->right = root;
	root->left->left = root->right;
	root->left = root->right = nullptr;
	return new_root; 
    }
};

int main(int argc, char** argv)
{
}
