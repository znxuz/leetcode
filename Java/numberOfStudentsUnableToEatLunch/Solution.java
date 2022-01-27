// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/

package numberOfStudentsUnableToEatLunch;

import java.util.ArrayDeque;
import java.util.Deque;

class Solution {

	// time complexity: O(n)
	// space complexity: O(1)
    public int countStudents(int[] students, int[] sandwiches) {
		int[] count = new int[2];
		int n = students.length;
		for (int s : students)
			count[s]++;
		int i = 0;
		while (i < n) {
			if (count[sandwiches[i]] == 0)
				break;
			count[sandwiches[i++]]--;
		}

		return n - i;
	}

	// time complexity: O(n^2)
	// space complexity: O(n)
    public int countStudentsSimulation(int[] students, int[] sandwiches) {
		Deque<Integer> studs = new ArrayDeque<>();
		Deque<Integer> foods = new ArrayDeque<>();
		for (int i = 0; i < students.length; ++i) {
			studs.offer(students[i]);
			foods.offerFirst(sandwiches[i]);
		}
		int initSize;
		do {
			initSize = studs.size();
			for (int i = 0; i < initSize; ++i) {
				int first = studs.poll();
				if (first == foods.peekLast())
					foods.pollLast();
				else
					studs.offer(first);
			}
		} while (initSize != studs.size());

		return studs.size();
    }
}
