// https://leetcode.com/problems/largest-triangle-area/

package largestTriangleArea;

import java.util.Arrays;

class Solution {

    public double largestTriangleArea(int[][] points) {
		double maxArea = Double.MIN_VALUE;
		for (int i = 0; i < points.length; i++) {
			for (int j = i + 1; j < points.length; j++) {
				for (int k = j + 1; k < points.length; k++) {
					maxArea = Math.max(maxArea, heron(points[i], points[j], points[k]));
					if (maxArea == Double.NaN)
						return maxArea;
				}
			}
		}
		return maxArea;
    }

	double heron(int[] a, int[] b, int[] c) {
		double side1 = pythagoras(a, b);
		double side2 = pythagoras(a, c);
		double side3 = pythagoras(b, c);
		double s = (side1 + side2 + side3) / 2;

		return Math.sqrt(s * Math.abs(s - side1) * Math.abs(s - side2) * Math.abs(s - side3));
	}

	double pythagoras(int[] a, int[] b) {
		double side1 = Math.abs(a[0] - b[0]);
		double side2 = Math.abs(a[1] - b[1]);
		return Math.sqrt(Math.pow(side1, 2) + Math.pow(side2, 2));
	}

}
