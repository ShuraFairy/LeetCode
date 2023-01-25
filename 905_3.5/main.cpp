#include <iostream>
#include <vector>
#include <cassert>
#include <type_traits>

class Solution {
public:
    std::vector<int> sortArrayByParity(std::vector<int>& nums)
    {
        std::vector<int>::size_type size = nums.size();
        int i = 0;
        int j = static_cast<int>(size) - 1;
        while (true)
        {
            while (i < j && (nums[i] % 2 == 0))
            {
                ++i;
            }
            while (i < j && (nums[j] % 2 != 0))
            {
                --j;
            }
            if (i < j)
            {
                std::swap(nums[i], nums[j]);
                ++i;
                --j;
            }
            else
                break;
        }
        return std::move(nums);
    }
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    std::vector<int> v{ 3,1,2,4 };
    Solution s; 
    v = s.sortArrayByParity(v);

    for (const auto& elem : v)
    {
        std::cout << elem << ',';
    }

	return EXIT_SUCCESS;
}
