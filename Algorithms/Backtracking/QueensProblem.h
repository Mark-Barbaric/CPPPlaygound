//
// Created by Mark Barbaric on 23/09/2019.
//

#ifndef BACKTRACKING_QUEENSPROBLEM_H
#define BACKTRACKING_QUEENSPROBLEM_H

#include <iostream>
#include <vector>


class QueensProblem {

    std::vector<std::vector<int>> chessTable;
    int numOfQueens {0};

public:

    QueensProblem(int numOfQueens_);
    void solve();

private:
    bool setQueens(int col);
    bool isPlaceValid(int row, int col) const;

    void printQueens() const;
};


#endif //BACKTRACKING_QUEENSPROBLEM_H
