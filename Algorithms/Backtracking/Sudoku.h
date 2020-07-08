#pragma once
#include <vector>
namespace Sudoku_Solver
{
	inline bool findUnassignedLocation(int* r, int* c, std::vector<std::vector<int>>& board)
	{
		for(int row = 0; row < board.size(); ++row)
		{
			for(int col = 0; col < board.size(); ++col)
			{
				if(board[row][col] == 0)
				{
					*r = row;
					*c = col;
					return true;
				}
			}
		}
		return false;
	}

	inline bool isUsedInBox(int startingRow, int startingColumn, std::vector<std::vector<int>>& board, int num)
	{
		for(int row = 0; row < 3; ++row)
		{
			for(int col = 0; col < 3; ++col)
			{
				if (board[startingRow + row][startingColumn + col] == num)
					return true;
			}
		}

		return false;
	}

	inline bool isUsedInColumn(int col, std::vector<std::vector<int>>& board, int num)
	{
		for(int row = 0; row < board.size(); ++row)
		{
			if (board[row][col] == num)
				return true;
		}

		return false;
	}
	
	inline bool isUsedInRow(int row, std::vector<std::vector<int>>& board, int num)
	{
		for(int col = 0; col < board.size(); ++col)
		{
			if (board[row][col] == num)
				return true;
		}
		return false;
	}

	inline bool isSafe(int r, int c, std::vector<std::vector<int>>& board, int num)
	{
		if (!isUsedInRow(r, board, num) &&
			!isUsedInColumn(c, board, num) &&
			!isUsedInBox(r - (r % 3), c - (c % 3), board, num) &&
			board[r][c] == 0)
			return true;

		return false;
	}

	inline bool solveSudoku(std::vector<std::vector<int>>& board)
	{
		int r = 0, c = 0;

		if (!findUnassignedLocation(&r, &c, board))
			return true;

		for(int num = 1; num <= 9; ++num)
		{
			if(isSafe(r, c, board, num))
			{
				board[r][c] = num;

				if (solveSudoku(board))
					return true;

				board[r][c] = 0;
			}
		}

		return false;
	}
	
}