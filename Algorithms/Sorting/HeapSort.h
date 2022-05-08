namespace Algorithms::SortingAlgorithms{

    void heapify(int index, int size, std::vector<int>& nums, bool max)
    {
        auto target = index;
        auto left = 2 * index + 1;
        auto right = 2 * index + 2;

        if (left < size && nums[left] > nums[target]) {
            target = left;
        }

        if (right < size && nums[right] > nums[target]) {
            target = right;
        }

        if(target != index){
            std::swap(nums[target], nums[index]);
            heapify(target, size, nums, max);
        }
    }

    void heapSort(std::vector<int>& nums, bool max)
    {
        for(int i = nums.size() / 2 - 1; i >= 0; --i){
            Heapify(i, nums.size(), nums, max);
        }

        for(int i = nums.size() - 1; i>= 0; --i){
            std::swap(nums[0], nums[i]);
            Heapify(0, i, nums, max);
        }
    }
}