namespace Algorithms::ArrayAlgorithms{

    inline int KadaneMaxSubArray(std::vector<int>& arr)
    {
        if (arr.size() == 0)
            return -1;

        auto currentSum = arr[0];
        auto maxSum = arr[0];

        for (int i = 1; i < arr.size(); ++i)
        {
            currentSum = std::max(arr[i], currentSum + arr[i]);
            maxSum = std::max(currentSum, maxSum);
        }

        return maxSum;
    }

}