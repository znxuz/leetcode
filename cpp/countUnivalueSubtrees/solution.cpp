// https://leetcode.com/problems/count-univalue-subtrees/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    int countUnivalSubtrees(TreeNode* root) 
    {
	return rec(root).second;
    }

private:
    std::pair<bool, size_t> rec(const TreeNode* root)
    {
	if (!root)
	    return {true, 0};
	if (!root->left && !root->right)
	    return {true, 1};

	auto left = rec(root->left);
	auto right = rec(root->right);
	bool same = (left.first & right.first)
	    && (root->left ? root->val == root->left->val : true)
	    && (root->right ? root->val == root->right->val : true);
	return {same, left.second + right.second + (same ? 1 : 0)};
    }
};

int main(int argc, char** argv)
{
}
