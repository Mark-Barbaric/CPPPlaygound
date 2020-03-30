//
// Created by Mark Barbaric on 23/09/2019.
//
#include "GraphColoring.h"
GraphColoring::GraphColoring(const std::vector <std::vector<int>>& graph_, int numOfColors_)
:graphMatrix(graph_),
 numOfColours(numOfColors_)
{
    colors.resize(graph_.size());
}

void GraphColoring::operator()()
{
    if(solve(0)){
        showResult();
    }
    else{
        std::cout << "No solution with the given parameters \n";
    }
}

bool GraphColoring::solve(size_t node)
{
    if(node == graphMatrix.size()){
        return true;
    }

    for(int colorIndex = 1; colorIndex <= numOfColours; ++colorIndex){

        if(isColorValid(node, colorIndex)){
            colors[node] = colorIndex;

            //check the next node
            if(solve(node + 1))
                return true;

            //BACKTRACK
        }
    }

    return false;
}

bool GraphColoring::isColorValid(size_t node, size_t color)
{
    for(size_t i = 0; i < graphMatrix.size(); ++i) {

        if(graphMatrix[node][i] == 1 && color == colors[i]){
            return false;
        }
    }
    return true;
}

void GraphColoring::showResult()
{
    for(size_t i = 0; i < graphMatrix.size(); ++i){
        std::cout << "Node " << (i + 1) << " has color index: " << colors[i] << "\n";
    }
}