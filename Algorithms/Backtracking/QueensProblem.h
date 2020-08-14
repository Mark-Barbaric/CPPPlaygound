#ifndef N_QUEENS_PROBLEM_H
#define N_QUEENS_PROBLEM_H

#include  <vector>

namespace NQueensProblem
{
	bool IsRowSafe(int r, int c, std::vector<std::vector<int>>& board)
	{
		for (int i = 0; i < c; i++)
			if (board[r][i])
				return false;

		return true;
	}
	
	bool IsLeftDiagonalSafe(int r, int c, std::vector<std::vector<int>>& board)
	{
		for (int i = r, j = c; i >= 0 && j >= 0; --i, --j)
			if (board[i][j])
				return false;

		return true;		
	}
	
	bool IsRightDiagonalSafe(int r, int c, std::vector<std::vector<int>>& board)
	{
		for(int i = r, j = c; i < board.size(), j >= 0, i < board.size(); ++i, --j)			
			if (board[i][j])
				return false;

		return true;
	}
	
	bool IsSafe(int r, int c, std::vector<std::vector<int>>& board)
	{
		if (IsRowSafe(r, c, board) &&
			IsLeftDiagonalSafe(r, c, board) &&
			IsRightDiagonalSafe(r, c, board))
			return true;

		return false;
	}

	bool SetQueens(int c, std::vector<std::vector<int>>& board)
	{
		if (c >= board.size())
			return true;

		for(int i = 0; i < board.size(); ++i)
		{
			if(IsSafe(i, c, board))
			{
				board[i][c]= 1;
				SetQueens(c + 1, board);
				board[i][c] = 0;
			}
		}

		return false;		
	}

	std::vector<std::vector<int>> SolveQueens(int n)
	{
		std::vector<std::vector<int>> board(n, std::vector<int>(n, 0));
		SetQueens(0, board);
		return board;
	}
}

#endif
