// https://leetcode.com/problems/search-in-a-binary-search-tree/

package searchInBST;

import utils.TreeNode;

class Solution {
	
   public TreeNode searchBST(TreeNode root, int val) {
	   return searchIter(root, val);
   }

   private TreeNode searchIter(TreeNode root, int val) {
	   while (root != null) {
		   if (val == root.val)
			   return root;
		   if (val < root.val)
			   root = root.left;
		   else
			   root = root.right;
	   }

	   return null;
   }

   private TreeNode searchRec(TreeNode root, int val) {
	   if (root == null)
		   return null;
	   if (val == root.val)
		   return root;
	   if (val < root.val)
		   return searchBST(root.left, val);
	   return searchBST(root.right, val);
   }

}
