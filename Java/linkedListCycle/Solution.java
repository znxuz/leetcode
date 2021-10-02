// https://leetcode.com/problems/linked-list-cycle/

package linkedListCycle;

import java.util.HashSet;
import java.util.Set;

import utils.ListNode;

public class Solution {

	public boolean hasCycle(ListNode head) {
		Set<ListNode> set = new HashSet<>();
		while (head != null) {
			if (set.contains(head))
				return true;
			set.add(head);
			head = head.next;
		}
		return false;
	}

	// Floyd's Cycle Finding Problem
	// time complexity: O(n)
	// space complexity: O(1)
    public boolean hasCycleFloyd(ListNode head) {
		var walker = head;
		var runner = head;

		while (runner != null && runner.next != null) {
			walker = walker.next;
			runner = runner.next.next;
			if (walker == runner)
				return true;
		}

		return false;
    }
}
