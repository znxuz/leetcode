// https://leetcode.com/problems/path-sum-ii/

#include <iostream>
#include <vector>

#include "helper.h"
#include "TreeNode.h"

using namespace std;
using namespace util;

class Solution
{
public:
	vector<vector<int>> pathSum(TreeNode* root, int target)
	{
		std::vector<std::vector<int>> res;
		std::vector<int> path;
		backtrack(res, path, root, target);
		return res;
	}

private:
	void backtrack(std::vector<std::vector<int>>& res, std::vector<int>& path,
			const TreeNode* root, int target)
	{
		if (!root)
			return;

		target -= root->val;
		path.push_back(root->val);
		if (!root->left && !root->right) {
			if (target == 0)
				res.push_back(path);
		} else {
			backtrack(res, path, root->left, target);
			backtrack(res, path, root->right, target);
		}
		target += root->val;
		path.pop_back();
	}

	std::vector<std::vector<int>> rec(const TreeNode* root, int target)
	{
		if (!root)
			return {};

		target -= root->val;

		if (!root->left && !root->right) {
			if (target == 0)
				return {{root->val}};
			return {};
		}
		auto left = pathSum(root->left, target);
		auto right = pathSum(root->right, target);
		for (auto& entry : right)
			left.push_back(std::move(entry));
		for (auto& entry : left)
			entry.insert(entry.begin(), root->val);


		return left;
	}
};

int main(int argc, char** argv)
{
}
