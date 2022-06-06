// https://leetcode.com/problems/count-complete-tree-nodes/

#include <cmath>
#include <iostream>
#include <vector>

#include "helper.h"
#include "TreeNode.h"

using namespace std;
using namespace util;

class Solution
{
public:
    int countNodes(TreeNode* root)
    {
	return optimal(root);
    }

private:
    int optimal(const TreeNode* root)
    {
	unsigned depth = tree_depth(root);
	if (!depth)
	    return 0;

	unsigned lo = 1, hi = static_cast<unsigned>(std::pow(2, depth - 1) - 1);
	while (lo <= hi) {
	    unsigned md = lo + (hi - lo) / 2;
	    if (valid_node(root, md, depth))
		lo = md + 1;
	    else
		hi = md - 1;
	}

	return static_cast<int>(std::pow(2, depth - 1) - 1 + lo);
    }

    bool valid_node(const TreeNode* node, size_t idx, unsigned depth)
    {
	unsigned lo = 0, hi = static_cast<unsigned>(std::pow(2, depth - 1) - 1);
	for (unsigned i = 0; i < depth - 1; ++i) {
	    unsigned md = lo + (hi - lo) / 2;
	    if (idx <= md) {
		hi = md;
		node = node->left;
	    } else {
		lo = md + 1;
		node = node->right;
	    }
	}

	return node;
    }

    unsigned tree_depth(const TreeNode* root)
    {
	// complete binary tree - leaves are all left-aligned
	return !root ? 0 : tree_depth(root->left) + 1;
    }
};

int main(int argc, char** argv)
{
}
