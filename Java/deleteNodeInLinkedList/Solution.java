// https://leetcode.com/problems/delete-node-in-a-linked-list/

package deleteNodeInLinkedList;

import utils.ListNode;

class Solution {

	// delete the given node without providing the head of the list
    public void deleteNode(ListNode node) {
		node.val = node.next.val;
		var next = node.next.next;
		node.next.next = null;
		node.next = next;
    }
}
