// https://leetcode.com/problems/palindrome-linked-list/

package palindromeLinkedList;

import utils.ListNode;

class Solution {

	ListNode reverseList(ListNode head) {
		if (head == null || head.next == null)
			return head;
		var node = reverseList(head.next);
		head.next.next = head;
		head.next = null;
		return node;
	}

	ListNode copyList(ListNode head) {
		if (head == null)
			return null;

		var newHead = new ListNode(head.val);
		var ret = newHead;
		while (head.next != null) {
			newHead.next = new ListNode(head.next.val);
			newHead = newHead.next;
			head = head.next;
		}

		return ret;
	}

    private ListNode endOfFirstHalf(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;
        while (fast.next != null && fast.next.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }
        return slow;
    }

	// time complexity: O(n)
	// space complexity: O(1) modify the list in-place
    public boolean isPalindrome(ListNode head) {
		var firstHalfEnd = endOfFirstHalf(head);
		var reversed = reverseList(firstHalfEnd.next);

		var isPalindrome = true;
		var p = reversed;
		while (isPalindrome && p != null) {
			if (head.val != p.val)
				isPalindrome = false;
			head = head.next;
			p = p.next;
		}
		firstHalfEnd.next = reverseList(reversed);
		
		return isPalindrome;
	}

	// time complexity: O(n * n * n) -> O(n)
	// space complexity: O(n) for extra reversed copy
    public boolean isPalindromeCopy(ListNode head) {
		var reversed = reverseList(copyList(head));

		while (head != null) {
			if (head.val != reversed.val)
				return false;
			head = head.next;
			reversed = reversed.next;
		}

		return true;
    }
}
