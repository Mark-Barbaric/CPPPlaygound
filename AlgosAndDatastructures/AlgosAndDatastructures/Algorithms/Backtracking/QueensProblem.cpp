//
// Created by Mark Barbaric on 23/09/2019.
//

#include "QueensProblem.h"
QueensProblem::QueensProblem(int numOfQueens_)
:numOfQueens(numOfQueens_)
{
    chessTable.resize(numOfQueens);

    for(auto& chessRow: chessTable)
        chessRow.resize(numOfQueens);

}

void QueensProblem::solve()
{
    if(setQueens(0))
        printQueens();
    else
        std::cout << "There is no solution... \n";
}

bool QueensProblem::setQueens(int col)
{
    if(col == numOfQueens)
        return true;

    for(int row = 0 ; row < numOfQueens; ++row){

        if(isPlaceValid(row, col)){
            chessTable[row][col] = 1;

            if(setQueens(col + 1)){
                return true;
            }
            chessTable[row][col] = 0;
        }
    }
    return false;
}

bool QueensProblem::isPlaceValid(int row, int col) const
{
    //check the current row
    for(int i = 0; i < col; ++i){
        if(chessTable[row][i] == 1)
            return false;
    }

    //check left to right diagonal
    for(int i = row, j = col; i >= 0 && j >= 0; --i, --j){
        if(chessTable[i][j] == 1)
            return false;
    }

    //check right to left diagonal
    for(int i = row, j = col; i < numOfQueens && j >= 0; ++i, --j){
        if(chessTable[i][j] == 1)
            return false;
    }

    return true;
}

void QueensProblem::printQueens() const
{

    for(size_t i = 0; i < chessTable.size(); ++i){
        for(size_t j = 0; j < chessTable.size(); ++j){
            if(chessTable[i][j] == 1){
                std::cout << " * ";
            }
            else{
                std::cout << " - ";
            }
        }
        std::cout << '\n';
    }
}