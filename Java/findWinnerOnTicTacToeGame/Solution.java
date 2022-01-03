// https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/

package findWinnerOnTicTacToeGame;

class Solution {

	private final char[][] grid = new char[3][3];
	private enum Direction {
		Horizontal, Vertical, Diagonal, AntiDiagonal
	}

    public String tictactoe(int[][] moves) {
		boolean turn = true;
		for (var m : moves) {
			char player = turn ? 'A' : 'B';
			turn = !turn;
			grid[m[0]][m[1]] = player;
			if (check(m[0], m[1], player))
				return String.valueOf(player);
		}

		return moves.length == grid.length * 3 ? "Draw" : "Pending";
    }

	// horizontal | vertical | diagonal | anti-diagonal
	public boolean check(int i, int j, char player) {
		boolean res = checkAlong(i, j, player, Direction.Horizontal, 0)
			|| checkAlong(i, j, player, Direction.Vertical, 0);
		if (i + j == grid.length - 1) {
			res |= checkAlong(i, j, player, Direction.AntiDiagonal, 0);
		} else if (i == j) {
			if (i == grid.length / 2)
				res |= checkAlong(i, j, player, Direction.AntiDiagonal, 0);
			res |= checkAlong(i, j, player, Direction.Diagonal, 0);
		}
		return res;
	}

	private boolean checkAlong(int i, int j, char player, Direction dir, int ctr) {
		if (grid[i][j] != player)
			return false;
		if (++ctr == grid.length)
			return true;
		switch(dir) {
			case Horizontal:
				j = ++j % grid[i].length;
				break;
			case Vertical:
				i = ++i % grid.length;
				break;
			case Diagonal:
				i = ++i % grid.length;
				j = ++j % grid[i].length;
				break;
			case AntiDiagonal:
				i = (i + grid.length - 1) % grid.length;
				j = ++j % grid[i].length;
				break;
		}
		return checkAlong(i, j, player, dir, ctr);
	}

	public void printGrid() {
		System.out.println("-----");
		for (var row : grid) {
			for (var cell : row)
				System.out.print((cell == 0 ? " " : cell) + " ");
			System.out.println();
			System.out.println("-----");
		}
	}

}
