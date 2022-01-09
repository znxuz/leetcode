package utils;

import java.util.ArrayList;
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

	public TrieNode(char c) {
		this();
		this.c = c;
	}

	public boolean containsSubstring(String word) {
		var trie = this;
		for (char c : word.toCharArray()) {
			int idx = c - 'a';
			if (trie.children[idx] == null)
				return false;
			trie = trie.children[idx];
		}
		return true;
	}

	public void add(String s) {
		var trie = this;
		for (int i = 0; i < s.length(); ++i) {
			int idx = s.charAt(i) - 'a';
			if (trie.children[idx] == null)
				trie.children[idx] = new TrieNode(s.charAt(i));
			trie = trie.children[idx];
			if (i == s.length() - 1)
				trie.end = true;
		}
	}

	public void add(List<String> list) {
		list.forEach(s -> this.add(s));
	}

	public List<String> getAllWords() {
		List<String> res = new ArrayList<>();

		getAllWords(this, res, "");
		return res;
	}

	private void getAllWords(TrieNode trie, List<String> list, String prev) {
		if (Character.isLetter(trie.c))
			prev += trie.c;
		if (trie.end == true)
			list.add(prev);
		for (var child : trie.children)
			if (child != null)
				getAllWords(child, list, prev);
	}

}

