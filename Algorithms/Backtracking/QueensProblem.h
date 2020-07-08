#ifndef N_QUEENS_PROBLEM_H
#define N_QUEENS_PROBLEM_H

#include  <vector>

namespace N_Queens_Problem
{
	bool isRowSafe(int r, int c, std::vector<std::vector<int>>& board)
	{
		for (int i = 0; i < c; i++)
			if (board[r][i])
				return false;

		return true;
	}
	
	bool isLeftDiagonalSafe(int r, int c, std::vector<std::vector<int>>& board)
	{
		for (int i = r, j = c; i >= 0 && j >= 0; --i, --j)
			if (board[i][j])
				return false;

		return true;		
	}
	
	bool isRightDiagonalSafe(int r, int c, std::vector<std::vector<int>>& board)
	{
		for(int i = r, j = c; i < board.size(), j >= 0, i < board.size(); ++i, --j)			
			if (board[i][j])
				return false;

		return true;
	}
	
	bool isSafe(int r, int c, std::vector<std::vector<int>>& board)
	{
		if (isRowSafe(r, c, board) &&
			isLeftDiagonalSafe(r, c, board) &&
			isRightDiagonalSafe(r, c, board))
			return true;

		return false;
	}

	bool setQueens(int c, std::vector<std::vector<int>>& board)
	{
		if (c >= board.size())
			return true;

		for(int i = 0; i < board.size(); ++i)
		{
			if(isSafe(i, c, board))
			{
				board[i][c]= 1;
				setQueens(c + 1, board);
				board[i][c] = 0;
			}
		}

		return false;		
	}
}

#endif
