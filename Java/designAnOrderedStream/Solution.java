// https://leetcode.com/problems/design-an-ordered-stream/

package designAnOrderedStream;

import java.util.ArrayList;
import java.util.List;

class Solution {

	class OrderedStream {

		private String[] buffer;
		private int ptr = 1;

		public OrderedStream(int n) {
			buffer = new String[n];
		}

		public List<String> insert(int idKey, String value) {
			buffer[idKey - 1] = value;
			List<String> ret = new ArrayList<>();
			if (idKey == ptr) {
				while (ptr <= buffer.length && buffer[ptr - 1] != null)
					ret.add(buffer[ptr++ - 1]);
			}

			return ret;
		}
	}

	/**
	 * Your OrderedStream object will be instantiated and called as such:
	 * OrderedStream obj = new OrderedStream(n);
	 * List<String> param_1 = obj.insert(idKey,value);
	 */

}
