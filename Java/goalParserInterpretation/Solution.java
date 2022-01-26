// https://leetcode.com/problems/goal-parser-interpretation/

package goalParserInterpretation;

class Solution {

	// time compleixty: O(n)
	// space complexity: O(n)
    public String interpret(String command) {
		var stringBuilder = new StringBuilder();
		for (int i = 0; i < command.length(); ++i) {
			if (command.charAt(i) == '(') {
				if (command.charAt(i + 1) == ')')
					stringBuilder.append('o');
			} else if (command.charAt(i) != ')')
				stringBuilder.append(command.charAt(i));
		}

		return stringBuilder.toString();
	}

	// time complexity: O(n)
	// space complexity: O(n)
    public String interpretReplace(String command) {
		return command.replace("()", "o").replaceAll("[()]", "");
    }
}
