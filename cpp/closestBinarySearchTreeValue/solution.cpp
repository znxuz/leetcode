// https://leetcode.com/problems/closest-binary-search-tree-value/

#include <climits>
#include <stack>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "helper.h"
#include "TreeNode.h"

#ifndef DEBUG
#define DEBUG 0
#endif

using namespace std;

class Solution
{
	public:
		int closestValue(TreeNode* root, double target)
		{
			return recH(root, target);
		}

		int recH(const TreeNode* root, const double target)
		{
			if (!root)
				return INT_MAX;

			if (target == root->val || (!root->left && !root->right))
				return root->val;
			int next = (root->val < target ? recH(root->right, target) : recH(root->left, target));
			return (std::abs(next - target) < std::abs(root->val - target) ? next : root->val);
		}

		int iterH(TreeNode* root, const double target)
		{
			if (!root)
				throw invalid_argument{"invalid tree root"};

			int closest = root->val;
			while (root) {
				int val = root->val;
				closest = (std::abs(val - target) < std::abs(closest - target) ? val : closest);
				root =  (target < val ? root->left : root->right);
			}
			return closest;
		}

		int iterN(TreeNode* root, const double target)
		{
			if (!root)
				throw invalid_argument{"invalid tree node"};

			stack<TreeNode*> stk;
			stk.push(root);
			int res = root->val;
			double diff = std::abs(target - res);
			while (!stk.empty()) {
				auto* node = stk.top();
				stk.pop();
				if (!node)
					continue;
				if (stk.empty() || stk.top() != node->right) {
					stk.push(node->right);
					stk.push(node);
					stk.push(node->left);
				} else {
					double cur = std::abs(target - node->val);
					if (cur < diff) {
						diff = cur;
						res = node->val;
					}
				}
			}

			return res;
		}

		// time: O(n)
		// space: O(n)
		int recN(const TreeNode* root, const double target)
		{
			if (!root)
				throw invalid_argument{"invalid tree node"};

			int lmin, rmin;
			lmin = rmin = root->val;
			if (!root->left && !root->right)
				return root->val;
			if (root->left)
				lmin = recN(root->left, target);
			if (root->right)
				rmin = recN(root->right, target);

			double diff = abs(target - root->val);
			double ldiff = abs(target - lmin);
			double rdiff = abs(target - rmin);
			double min = std::min(diff, std::min(ldiff, rdiff));
			return (diff == min) ? root->val : ldiff == min ? lmin : rmin;
		}
};

int main(int argc, char** argv)
{
}
