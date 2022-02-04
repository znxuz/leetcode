// https://leetcode.com/problems/determine-color-of-a-chessboard-square/

package determineColorOfAChessboardSquare;

class Solution {

    public boolean squareIsWhite(String coordinates) {
		return (coordinates.charAt(0) + coordinates.charAt(1)) % 2 != 0;
    }
}
