// https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/

package deleteNNodesAfterMNodesOfLinkedList;

import utils.ListNode;

class Solution {

    public ListNode deleteNodes(ListNode head, int m, int n) {
		return deleteNodesRec(head, m, n, 0);
	}

	// recursive
	// time complexity: O(n)
	// space complexity: O(1)
	public ListNode deleteNodesRec(ListNode head, int m, int n, int i) {
		if (head == null)
			return null;

		var next = deleteNodesRec(head.next, m, n, (i + 1) % (m + n));
		if (i == m - 1)
			head.next = next;
		if (i == m + n - 1)
			head.next = null;
		return (i < m) ? head : next;

	}

	// iterative
	// time complexity: O(n)
	// space complexity: O(1)
    public ListNode deleteNodesIter(ListNode head, int m, int n) {
		int keep = 1;
		int lose = 0;
		var cur = head;
		var anchor = head;
		while (cur != null) {
			ListNode next = null;
			if (keep < m) {
				keep++;
				next = cur.next;
			} else if (keep == m && lose == 0) {
				anchor = cur;
				lose = n;
				next = cur.next;
			} else if (lose > 1) {
				lose--;
				next = cur.next;
			} else {
				keep = 1;
				anchor.next = cur.next;
				cur.next = null;
				next = anchor.next;
				lose = 0;
			}
			cur = next;
		}
		if (lose > 0)
			anchor.next = null;

		return head;
    }

}
