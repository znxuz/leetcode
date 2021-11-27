// https://leetcode.com/problems/shortest-completing-word/

package shortestCompletingWord;

import java.util.HashMap;
import java.util.Map;

class Solution {

	// time complexity: O(n * m)
	// space ocmplexity: O(1) or O(n) for n products from method getPrimeProduct() ?
    public String shortestCompletingWordPrime(String licensePlate, String[] words) {
		int[] primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,
			47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};
		long product = getPrimeProduct(licensePlate, primes);

		String result = "";
		int minLen = Integer.MAX_VALUE;
		for (var word : words) {
			if (word.length() < minLen && getPrimeProduct(word, primes) % product == 0) {
				result = word;
				minLen = word.length();
			}
		}

		return result;
	}

	private long getPrimeProduct(String word, int[] primeMap) {
		long product = 1;
		for (char c : word.toCharArray()) {
			if (Character.isAlphabetic(c)) {
				c = Character.toLowerCase(c);
				product *= primeMap[c - 'a'];
			}
		}

		return product;
	}

	// time complexity: O(n * m)
	// space complexity: O(n)
    public String shortestCompletingWordArray(String licensePlate, String[] words) {
		int[] licenseCounts = getCount(licensePlate);
		int[] wordCounts;
		String result = "";
		int minLen = Integer.MAX_VALUE;
		for (var word : words) {
			wordCounts = getCount(word);
			int i = 0;
			while (i < 26) {
				if (wordCounts[i] < licenseCounts[i])
					break;
				i++;
			}
			if (i != 26)
				continue;
			if (word.length() < minLen) {
				result = word;
				minLen = word.length();
			}
		}

		return result;
	}

	private int[] getCount(String word) {
		int[] count = new int[26];
		for (char c : word.toCharArray()) {
			if (Character.isLetter(c)) {
				count[Character.toLowerCase(c) - 'a']++;
			}
		}

		return count;
	}

	// time complexity: O(n * m): n for words.length, m for word.length()
	// space complexity: O(n) for map
    public String shortestCompletingWordBruteForce(String licensePlate, String[] words) {
		Map<Character, Integer> map = new HashMap<>();
		int len = 0;
		for (char c : licensePlate.toCharArray()) {
			if (Character.isAlphabetic(c)) {
				c = Character.toLowerCase(c);
				map.put(c, map.getOrDefault(c, 0) + 1);
				len++;
			}
		}

		int idx = -1;
		int minLen = Integer.MAX_VALUE;
		for (int i = 0; i < words.length; i++) {
			int wordLen = words[i].length();
			if (wordLen < len)
				continue;
			Map<Character, Integer> tmpMap = new HashMap<>();
			tmpMap.putAll(map);
			if (matchWord(words[i], tmpMap) && wordLen < minLen) {
				minLen = wordLen;
				idx = i;
			}
		}

		return words[idx];
    }

	private boolean matchWord(String word, Map<Character, Integer> map) {
		for (char c : word.toCharArray()) {
			c = Character.toLowerCase(c);
			if (map.containsKey(c)) {
				if (map.get(c) == 1)
					map.remove(c);
				else
					map.put(c, map.get(c) - 1);
			}
		}

		return map.size() == 0;
	}

}
