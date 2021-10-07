// https://leetcode.com/problems/reverse-linked-list/

package reverseLinkedList;

import utils.ListNode;

class Solution {

	private ListNode reverseListIter(ListNode head) {
		if (head == null)
			return null;

		ListNode prev = null;
		ListNode current = head;
		while (current != null) {
			var next = current.next;
			current.next = prev;
			prev = current;
			current = next;
		}
		return prev;
	}

	private ListNode reverseListRec(ListNode head) {
		if (head == null || head.next == null)
			return head;
		var node = reverseListRec(head.next);
		head.next.next = head;
		head.next = null;
		return node;
	}

	private void append(ListNode head, ListNode node) {
		if (head.next == null)
			head.next = node;
		else
			append(head.next, node);
	}

	// 1 -> 2 -> 3 -> 4 -> 5
	// time complexity: O(n^2)
	// space complexity: O(n^2)
	// bad recursive solution!
	private ListNode reverseListRecBad(ListNode head) {
		if (head == null)
			return null;
		if (head.next == null)
			return head;
		var newHead = reverseListRec(head.next);
		append(newHead, head);
		head.next = null;
		return newHead;
	}

    public ListNode reverseList(ListNode head) {
		return reverseListRec(head);
    }
}
