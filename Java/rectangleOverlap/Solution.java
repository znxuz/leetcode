// https://leetcode.com/problems/rectangle-overlap/

package rectangleOverlap;

class Solution {

	// (x1, y1) -> bottom left
	// (x2, y2) -> top right
	// rec[] = {x1, y1, x2, y2}
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        return rec1[2] > rec2[0] && rec1[3] > rec2[1] &&
                 rec1[0] < rec2[2] && rec1[1] < rec2[3];
    }
}
