#pragma once

namespace util
{
	struct TreeNode
	{
		int val;
		TreeNode* left;
		TreeNode* right;

		TreeNode() : val{0}, left{nullptr}, right{nullptr}
		{}

		TreeNode(int val) : val{val}, left{nullptr}, right{nullptr}
		{}

		TreeNode(int val, TreeNode* left, TreeNode* right)
			: val{val}, left{left}, right{right}
		{}
	};

	inline void delete_tree(TreeNode* root)
	{
		if (!root)
			return;
		delete_tree(root->left);
		delete_tree(root->right);
		delete root;
	}


	inline void inorder(const TreeNode* root, void (*f)(int))
	{
		if (!root)
			return;
		inorder(root->left, f);
		f(root->val);
		inorder(root->right, f);
	}

};
