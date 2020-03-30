//
// Created by Mark Barbaric on 23/09/2019.
//
#ifndef BACKTRACKING_COLORINGPROBLEM_H
#define BACKTRACKING_COLORINGPROBLEM_H

#include <vector>
#include <iostream>

class GraphColoring {

    const std::vector<std::vector<int>> & graphMatrix;
    std::vector<int> colors;
    int numOfColours;

public:
    GraphColoring(const std::vector<std::vector<int>>& graph_, int numOfColors_);
    void operator()();

private:

    bool solve (size_t node);
    bool isColorValid(size_t node, size_t color);
    void showResult();

};


#endif //BACKTRACKING_COLORINGPROBLEM_H
