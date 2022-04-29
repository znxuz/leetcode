// https://leetcode.com/problems/merge-two-binary-trees/

#include <iostream>
#include <vector>

#include "helper.h"
#include "TreeNode.h"

using namespace std;
using namespace util;

class Solution
{
public:
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
	{
		return rec(root1, root2);
	}

private:
	TreeNode* rec(TreeNode* root1, TreeNode* root2)
	{
		if (!root1 && !root2)
			return nullptr;
		if (!root1 || !root2)
			return (!root1 ? root2 : root1);

		TreeNode* root = new TreeNode(root1->val + root2->val);
		root->left = rec(root1->left, root2->left);
		root->right = rec(root1->right, root2->right);
		return root;
	}
};

int main(int argc, char** argv)
{
}
