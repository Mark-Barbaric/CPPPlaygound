#include "include/catch.hpp"
#include "QueensProblem.h"

namespace Algorithms::Backtracking{

    TEST_CASE("Queen Problem Tests"){

        std::vector<std::vector<std::string>> expectedAns {
            {".Q..","...Q","Q...","..Q."},
            {"..Q.","Q...","...Q",".Q.."}
        };

        const auto ans = solveNQueens(4);
        REQUIRE(ans == expectedAns);
    }
}