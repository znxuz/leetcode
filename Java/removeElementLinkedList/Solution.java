// https://leetcode.com/problems/remove-linked-list-elements/

package removeElementLinkedList;

import utils.ListNode;

class Solution {

	// 2 -> 2 -> 3 -> 5 -> 7 -> 9
	private ListNode removeElementsIter(ListNode head, int val) {
		while (head != null && head.val == val)
			head = head.next;
		if (head == null)
			return null;

		var current = head;
		while (current.next != null) {
			if (current.next.val == val)
				current.next = current.next.next;
			else
				current = current.next;
		}

		return head;
	}

	private ListNode removeElementsRec(ListNode head, int val) {
		if (head == null)
			return null;
		if (head.val == val)
			return removeElementsRec(head.next, val);
		head.next = removeElementsRec(head.next, val);
		return head;
	}

    public ListNode removeElements(ListNode head, int val) {
		return removeElementsRec(head, val);
    }
}
