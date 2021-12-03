// https://leetcode.com/problems/similar-rgb-color/

package similarRGBColor;

class Solution {

	// dont know what it wants.
	// solution copied
    public String similarRGB(String color) {
		String[] li = {"00", "11", "22", "33", "44", "55", "66", "77", "88", "99", "aa", "bb", "cc", "dd", "ee", "ff"};
		StringBuilder sb = new StringBuilder();
		sb.append("#");
		
		for (int c = 1 ;c < color.length(); c=c+2) {
			
			String hex = color.substring(c, c+2);
			
			int num = Integer.MAX_VALUE;
			String rgb = "";
			
			for (String i : li){
				int res  = Math.abs(Integer.parseInt(hex, 16) - Integer.parseInt(i, 16));
				if (res < num){
					num = res;
					rgb = i;
				}
			}
			sb.append(rgb);
		}
		
		
		return sb.toString();
    }
}
