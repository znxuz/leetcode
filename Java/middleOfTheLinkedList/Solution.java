// https://leetcode.com/problems/middle-of-the-linked-list/

package middleOfTheLinkedList;

import utils.ListNode;

class Solution {

	// fast and slow pointer
	// time complexity: O(n)
	// space complexity: O(1)
    public ListNode middleNode(ListNode head) {
		var fast = head;
		var slow = head;
		while (fast != null && fast.next != null) {
			fast = fast.next.next;
			slow = slow.next;
		}

		return slow;
    }

}
