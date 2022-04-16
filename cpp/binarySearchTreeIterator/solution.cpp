// https://leetcode.com/problems/binary-search-tree-iterator/

#include <algorithm>
#include <stack>
#include <iostream>
#include <vector>

#include "helper.h"
#include "TreeNode.h"

using namespace std;
using namespace util;

// ctor: O(h)
// next: O(h)
// hasNext: O(1)
class BSTIterator
{
public:
	BSTIterator(TreeNode* root)
	{
		while (root)
			stk.push(std::exchange(root, root->left));
	}

	int next()
	{
		auto* node = stk.top();
		stk.pop();
		int ret = node->val;
		if (node->right) {
			node = node->right;
			while (node)
				stk.push(std::exchange(node, node->left));
		}

		return ret;
	}

	bool hasNext()
	{
		return !stk.empty();
	}

private:
	std::stack<const TreeNode*> stk;
};

// ctor: O(n)
// next: O(1)
// hasNext: O(1)
class BSTIteratorVector
{
public:
	BSTIteratorVector(TreeNode* root)
	{
		build(root);
	}

	int next()
	{
		return vals[idx++];
	}

	bool hasNext()
	{
		return idx < vals.size();
	}

private:
	std::vector<int> vals;
	size_t idx = 0;

	void build(const TreeNode* root)
	{
		if (!root)
			return;
		build(root->left);
		vals.push_back(root->val);
		build(root->right);
	}
};

int main(int argc, char** argv)
{
}
