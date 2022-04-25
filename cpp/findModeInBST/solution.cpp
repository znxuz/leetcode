// https://leetcode.com/problems/find-mode-in-binary-search-tree/

#include <unordered_map>
#include <iostream>
#include <vector>

#include "helper.h"
#include "TreeNode.h"

using namespace std;
using namespace util;

class Solution
{
public:
	// time: O(n)
	// space: O(n)
	vector<int> findMode(TreeNode* root)
	{
		std::unordered_map<int, int> freq;
		inorder(root, freq);
		std::vector<int> res;
		int max = 0;
		for (const auto& [key, cnt] : freq) {
			if (cnt >= max) {
				if (cnt > max)
					res.clear();
				res.push_back(key);
			}
			max = std::max(max, cnt);
		}

		return res;
	}

private:
	void inorder(const TreeNode* root, std::unordered_map<int, int>& freq)
	{
		if (!root)
			return;
		inorder(root->left, freq);
		++freq[root->val];
		inorder(root->right, freq);
	}
};

int main(int argc, char** argv)
{
}
