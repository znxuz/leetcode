// https://leetcode.com/problems/intersection-of-two-linked-lists/

package intersectionTwoLinkedLists;

import java.util.HashSet;
import java.util.Set;

import utils.ListNode;

public class Solution {

	private int getListSize(ListNode head) {
		if (head == null)
			return 0;
		return 1 + getListSize(head.next);
	}

	private ListNode offsetList(ListNode head, int diff) {
		while (diff-- > 0)
			head = head.next;

		return head;
	}

	// optimized
	// time complexity: O(n + m)
	// space complexity: O(1)
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
		var pA = headA;
		var pB = headB;

		while (pA != pB) {
			pA = pA == null ? headB : pA.next;
			pB = pB == null ? headA : pB.next;
		}

		return pA;
	}

    public ListNode getIntersectionNodeBad(ListNode headA, ListNode headB) {
		int sizeA = getListSize(headA);
		int sizeB = getListSize(headB);

		if (sizeA > sizeB)
			headA = offsetList(headA, sizeA - sizeB);
		else if (sizeA < sizeB)
			headB = offsetList(headB, sizeB - sizeA);

		while (headA != null && headB != null) {
			if (headA == headB)
				return headA;
			headA = headA.next;
			headB = headB.next;
		}

		return null;
	}

    public ListNode getIntersectionNodeSet(ListNode headA, ListNode headB) {
		Set<ListNode> set = new HashSet<>();

		while (headA != null) {
			set.add(headA);
			headA = headA.next;
		}

		while (headB != null) {
			if (set.contains(headB))
				return headB;
			headB = headB.next;
		}

		return null;
    }
}
