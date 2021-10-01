// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

package removeDuplicateSortedList;

import utils.ListNode;

class Solution {

	// TOREFRESH: recursion
	// time complexity: O(n)
	// space complexity: O(n)
	public ListNode deleteDuplicatesRec(ListNode head) {
		if (head == null || head.next == null)
			return head;
		if (head.val == head.next.val)
			head = deleteDuplicatesRec(head.next);
		else
			head.next = deleteDuplicatesRec(head.next);
		return head;
	}

	// time complexity: O(n)
	// space complexity: O(1)
    public ListNode deleteDuplicates(ListNode head) {
		if (head == null)
			return null;

		ListNode current = head;
		ListNode next = current.next;
		while (current != null) {
			while (next != null && current.val == next.val)
				next = next.next;
			current.next = next;
			current = next;
			next = next == null ? null : next.next;
		}
		return head;
    }
}
