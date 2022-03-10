// https://leetcode.com/problems/same-tree/

#include <stack>
#include <iostream>
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
		bool isSameTree(TreeNode* p, TreeNode* q)
		{
			return iter(p, q);
		}

		bool rec(TreeNode* p, TreeNode* q)
		{
			if (!p && !q)
				return true;
			if (!p || !q || p->val != q->val)
				return false;

			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		}

		bool iter(TreeNode* p, TreeNode* q)
		{
			stack<TreeNode*> st;
			st.push(p);
			st.push(q);
			while (!st.empty()) {
				q = st.top();
				st.pop();
				p = st.top();
				st.pop();
				if (!p && !q)
					continue;
				if (!p || !q || p->val != q->val)
					return false;
				st.push(p->left);
				st.push(q->left);
				st.push(p->right);
				st.push(q->right);
			}

			return true;
		}
};

int main(int argc, char** argv)
{
}
