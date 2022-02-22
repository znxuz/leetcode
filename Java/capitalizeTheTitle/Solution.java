// https://leetcode.com/problems/capitalize-the-title/

package capitalizeTheTitle;

class Solution {

    public String capitalizeTitle(String title) {
		String[] words = title.split("\\s");

		for (int i = 0; i < words.length; ++i) {
			char[] w = words[i].toCharArray();
			for (int j = 0; j < w.length; ++j) {
				w[j] = (j == 0 && w.length > 2)
					? Character.toUpperCase(w[j]) : Character.toLowerCase(w[j]);
			}
			words[i] = String.valueOf(w);
		}

		return String.join(" ", words);
    }
}
