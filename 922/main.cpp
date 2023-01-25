#include <iostream>
#include <vector>
#include <cassert>

class Solution {
public:
    std::vector<int> sortArrayByParity(std::vector<int>& nums) 
    {
        std::vector<int>::size_type size = nums.size();
        std::vector<int> temp;
        temp.resize(size);
        int i = 0;
        int j = 0;

        //[4, 2, 5, 7]
        //for (i = j; i < size; ++i)                
        /*while (temp.size() != size)
        {
            j = temp.size();
            if (nums[i] % 2 == 0 && (i % 2 == 0))
                temp.at(i) = nums[i];                   
            if (nums[i] % 2 != 0 && (i % 2 != 0))
                temp.at(i) = nums[i];

            if ((temp.size() != j))
                ++i;
        }*/

        return temp;
    }    
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    std::vector<int> v{ 4,2,5,7 };
    Solution s; 
    v = s.sortArrayByParity(v);

    for (const auto& elem : v)
    {
        std::cout << elem << ',';
    }

	return EXIT_SUCCESS;
}
