#include <gtest/gtest.h>
#include "QueensProblem.h"
#include "NumTiles.h"

namespace Algorithms::Backtracking{

    TEST(BacktrackingTests, NumTileTests){

        const auto ans1 = numTilePossibilities("AAB");
        EXPECT_EQ(ans1, 8);

        const auto ans2 = numTilePossibilitiesOptimized("AAB");
        EXPECT_EQ(ans2, 8);

    }

    TEST(BacktrackingTests, QueenProblemTests){

        std::vector<std::vector<std::string>> expectedAns {
            {".Q..","...Q","Q...","..Q."},
            {"..Q.","Q...","...Q",".Q.."}
        };

        const auto ans = solveNQueens(4);
    //    EXPECT_EQ(ans, expectedAns);
    }
}