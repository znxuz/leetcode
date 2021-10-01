// https://leetcode.com/problems/merge-two-sorted-lists/

package mergeTwoSortedList;

import utils.ListNode;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
		ListNode head = new ListNode(-1);
		ListNode headPrev = head;

		while (l1 != null && l2 != null) {
			if (l2.val > l1.val) {
				head.next = l1;
				l1 = l1.next;
				head = head.next;
			} else {
				head.next = l2;
				l2 = l2.next;
				head = head.next;
			}
		}
		head.next = l1 == null ? l2 : l1;

		return headPrev.next;
	}

	// time complexity: O(n)
	// space complexity: O(n)
    public ListNode mergeTwoListsRec(ListNode l1, ListNode l2) {
		if (l2 == null)
			return l1;
		if (l1 == null)
			return l2;

		if (l1.val >= l2.val) {
			l2.next = mergeTwoListsRec(l1, l2.next);
			return l2;
		} else {
			l1.next = mergeTwoListsRec(l2, l1.next);
			return l1;
		}
    }
}
