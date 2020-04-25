#ifndef NUM_COMBINATIONS_H
#define NUM_COMBINATIONS_H

#include <vector>
class NumCombinations{
  
  const int numScores;
  const int finalScore;
  std::unique_ptr<std::vector<std::vector<int>>> combinationsMatrix;
  std::unique_ptr<std::vector<int>> combinationsVector;
  
  inline void recursiveCombinationsSearch(const int min, const int target, std::vector<int> scores, std::vector<int> temp, std::vector<std::vector<int>>& combinationsMatrix)
  {
    if (target == 0)
      combinationsMatrix.push_back(temp);

    for (int i = 0; i < scores.size(); ++i)
    {
      if (target - scores[i] >= 0 && scores[i] >= min)
      {
        temp.push_back(scores[i]);
        recursiveCombinationsSearch(scores[i], target - scores[i], scores, temp, combinationsMatrix);
        temp.pop_back();
      }
    }
  }
  
public:
  
  NumCombinations(const int numScores_,
                  const int finalScore_)
  :numScores(numScores_),
  finalScore(finalScore_)
  {
    combinationsMatrix.reset(new std::vector<std::vector<int>>(numScores, std::vector<int>(finalScore + 1, 0)));
    combinationsVector.reset(new std::vector<int> (finalScore + 1, 0));
  }
  
  const int numCombinations(const int finalScore, std::vector<int> scores)
  {
    for (int i = 0; i < scores.size(); ++i)
    {
      //only one way to get a score of 0
      (*combinationsMatrix)[i][0] = 1;

      for (int j = 1; j <= finalScore; ++j)
      {
        //take previous calculated work [i - 1]
        const auto withoutThisScore = i > 0 ? (*combinationsMatrix)[i - 1][j] : 0;
        const auto withThisScore = j >= scores[i] ? (*combinationsMatrix)[i][j - scores[i]] : 0;
        (*combinationsMatrix)[i][j] = withThisScore + withoutThisScore;
      }
    }

    return (*combinationsMatrix).back().back();
  }

  const int numCombinationsOptimised(const int finalScore, std::vector<int> scores)
  {
    (*combinationsVector)[0] = 1;

    for (int i = 0; i < scores.size(); ++i)
    {
      const auto score = scores[i];

      for (int j = score; j <= finalScore; ++j)
      {
        (*combinationsVector)[j] += (*combinationsVector)[j - score];
      }
    }

    return (*combinationsVector).back();
  }

  std::vector<std::vector<int>> numCombinationsOutcomes(const int finalScore, const std::vector<int> scores)
  {
    std::vector<std::vector<int>> scoreCombinations;
    std::vector<int> temp;
    recursiveCombinationsSearch(0, finalScore, scores, temp, scoreCombinations);
    return scoreCombinations;
  }
  
};


#endif
