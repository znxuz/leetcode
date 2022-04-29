// https://leetcode.com/problems/construct-string-from-binary-tree/

#include <iostream>
#include <vector>

#include "helper.h"
#include "TreeNode.h"

using namespace std;
using namespace util;

class Solution
{
public:
	string tree2str(TreeNode* root)
	{
		return rec(root);
	}

private:
	std::string rec(const TreeNode* root)
	{
		if (!root)
			return "";

		std::string res = std::to_string(root->val);
		if (root->left || root->right) {
			res += '(' + rec(root->left) + ')';
			if (root->right)
				res += '(' + rec(root->right) + ')';
		}

		return res;
	}

	void rec_ref(const TreeNode* root, std::string& res)
	{
		if (!root)
			return;

		res += std::to_string(root->val);
		if (root->left || root->right) {
			res.push_back('(');
			rec_ref(root->left, res);
			res.push_back(')');
			if (root->right) {
				res.push_back('(');
				rec_ref(root->right, res);
				res.push_back(')');
			}
		}
	}
};

int main(int argc, char** argv)
{
}
