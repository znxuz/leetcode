// https://leetcode.com/problems/average-of-levels-in-binary-tree/

#include <queue>
#include <iostream>
#include <vector>

#include "helper.h"
#include "TreeNode.h"

using namespace std;
using namespace util;

class Solution
{
public:
	vector<double> averageOfLevels(TreeNode* root)
	{
		std::vector<double> res;
		std::queue<const TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			double sum = 0;
			unsigned size = 0;
			for (size_t i = que.size(); i-- > 0;) {
				const TreeNode* node = que.front();
				que.pop();
				if (!node)
					continue;

				sum += node->val;
				++size;
				que.push(node->left);
				que.push(node->right);
			}
			if (size)
				res.push_back(sum / size);
		}

		return res;
	}
};

int main(int argc, char** argv)
{
}
