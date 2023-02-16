#include <iostream>
#include <vector>
#include <cassert>
#include <type_traits>

//// 1 version
//class Solution {
//public:
//    std::vector<int> sortArrayByParity(std::vector<int>& nums)
//    {
//        std::vector<int>::size_type size = nums.size();
//        std::vector<int> res(size);
//        int even = 0;
//        int odd = 1;
//        
//        for (int elem : nums)
//        {
//            if ((elem & 1) == 0) // смотрим на последний бит, если 0, то четный
//            {
//                res[even] = elem;
//                even += 2;
//            }
//            else
//            {
//                res[odd] = elem;
//                odd += 2;
//            }
//        }
//        
//        return res;
//    }
//};

// 2 version
class Solution {
public:
    std::vector<int> sortArrayByParity(std::vector<int>& nums)
    {
        std::vector<int>::size_type size = nums.size();        
        int even = (int)size - 2;
        int odd = (int)size - 1;

        while (true)
        {
            while (even >= 0 && (nums[even] & 1) == 0)
            {
                even -= 2;
            }
            while (odd >= 0 && (nums[odd] & 1) == 1)
            {
                odd -= 2;
            }
            if (even >= 0)
            {
                std::swap(nums[even], nums[odd]);
                even -= 2;
                odd -= 2;
            }
            else
                break;
        }
        return std::move(nums);
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
