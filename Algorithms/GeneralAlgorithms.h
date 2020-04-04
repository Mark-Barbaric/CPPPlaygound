
class GeneralAlgorithms
{
public:
    GeneralAlgorithms() = default;

    std::vector<int> productExceptSelf(std::vector<int>& nums, size_t size)
    {
        int* l = new int[size];
        int* r = new int[size];
        std::vector<int> ans (size);

        l[0] = 1;
        for(int i = 1; i < size; ++i)
        {
            auto result = nums[i - 1] * l[i - 1];
            l[i] = result;
        }

        r[size - 1] = 1;

        for(int i = size - 2; i >= 0; --i)
        {
            auto result = nums[i + 1] * r[i + 1];
            r[i] = result;
        }

        for(int i = 0; i < size; ++i)
        {
            ans[i] = l[i] * r[i];
        }

        return ans;
    }

};
