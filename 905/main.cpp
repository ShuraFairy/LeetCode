#include <iostream>
#include <vector>
#include <cassert>

class Solution {
public:
    std::vector<int> sortArrayByParity(std::vector<int>& nums) 
    {
        std::vector<int>::size_type size = nums.size();
        std::vector<int> temp;
        temp.reserve(size);

        for (size_t i = 0; i < size; ++i)
        {
            if (nums[i] % 2 == 0)
                temp.push_back(nums[i]);            
        }

        for (size_t i = 0; i < size; ++i)
        {
            if (nums[i] % 2 != 0)
                temp.push_back(nums[i]);
        }

        return temp;
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
