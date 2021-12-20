// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

package sumOfRootToLeafBinaryNumbers;

import utils.TreeNode;

class Solution {

    public int sumRootToLeaf(TreeNode root) {
		return sumRootToLeafIter(root);
    }

	// time complexity: O(n)
	// space complexity: O(h)
    public int sumRootToLeafRec(TreeNode root, int prev) {
		if (root == null)
			return 0;

		prev = prev * 2 + root.val; // much better than adding string: double a num to left shift
		if (root.left == null && root.right == null)
			return prev;
		return sumRootToLeafRec(root.left, prev) + sumRootToLeafRec(root.right, prev);
    }

    public int sumRootToLeafIter(TreeNode root) {
		return -1;
		// TODO morries constant time iter traverse
		// 	https://www.youtube.com/watch?v=wGXB9OWhPTg
		// 	https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/solution/
    }

}
