package utils;

import java.util.List;

public class TrieNode {

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

	public static void getAllWords(TrieNode trie, List<String> list, String prev) {
		if (Character.isLetter(trie.c))
			prev += trie.c;
		if (trie.end == true)
			list.add(prev);
		for (var child : trie.children)
			if (child != null)
				getAllWords(child, list, prev);
	}

}

