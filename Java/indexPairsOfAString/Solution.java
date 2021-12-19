// https://leetcode.com/problems/index-pairs-of-a-string/

package indexPairsOfAString;

import java.util.ArrayList;
import java.util.List;

class Solution {

    public int[][] indexPairs(String text, String[] words) {
		var trie = new TrieNode();
		for (var w : words)
			TrieNode.add(trie, w);
		List<int[]> indices = new ArrayList<>();
		for (int i = 0; i < text.length(); ++i) {
			var cur = trie;
			for (int j = i; j < text.length(); ++j) {
				var child = cur.children[text.charAt(j) - 'a'];
				if (child == null) 
					break;
				 if (child.end == true)
					indices.add(new int[]{i, j});
				cur = child;
			}
		}

		return indices.stream().toArray(int[][]::new);
    }

	static class TrieNode {

		public char c;
		public TrieNode[] children;
		public boolean end;

		public TrieNode() {
			this.c = ' ';
			this.children = new TrieNode[26];
			this.end = false;
		}

		public TrieNode(char c, boolean end) {
			this();
			this.c = c;
			this.end = end;
		}

		public static void add(TrieNode trie, String s) {
			for (int i = 0; i < s.length(); ++i) {
				char cur = s.charAt(i);
				if (trie.children[cur - 'a'] == null)
					trie.children[cur - 'a'] = new TrieNode(cur, false);
				if (i == s.length() - 1)
					trie.children[cur - 'a'].end = true;
				trie = trie.children[cur - 'a'];
			}
		}

	}

}
