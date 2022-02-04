// https://leetcode.com/problems/find-center-of-star-graph/

package findCenterOfStarGraph;

class Solution {

    public int findCenter(int[][] edges) {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				if (edges[0][i] == edges[1][j])
					return edges[0][i];
			}
		}

		return -1;
    }
}
