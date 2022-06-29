// https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    int longestConsecutive(TreeNode* root) 
    {
	return rec(root).second;
    }

private:
    // time: O(n)
    // space: O(n)
    std::pair<int, int> rec(const TreeNode* root)
    {
	if (!root)
	    return {0, 0};
	if (!root->left && !root->right)
	    return {1, 1};

	auto [lcur, lmax] = rec(root->left);
	lcur = (root->left && root->left->val == root->val + 1 ? ++lcur : 1);
	lmax = std::max(lmax, lcur);

	auto [rcur, rmax] = rec(root->right);
	rcur = (root->right && root->right->val == root->val + 1 ? ++rcur : 1);
	rmax = std::max(rmax, rcur);

	return {std::max(lcur, rcur), std::max(lmax, rmax)};
    }
};

int main(int argc, char** argv)
{
}
