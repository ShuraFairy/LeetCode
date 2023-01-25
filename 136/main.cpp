#include <cassert>
#include <deque>
#include <ios>
#include <iostream>
#include <queue>
#include <tuple>
#include <type_traits>
#include <vector>
#include <bitset>
#include <array>

const int FASTIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

// 1 version
class Solution 
{
public:
    int singleNumber(std::vector<int>& nums) 
    {
        std::vector<int> a(10, 0);
        int value = 0;
        std::vector<int>::size_type size = nums.size();
        for (size_t i = 0; i < size; ++i)
        {
            a[nums[i]]++;
        }
      
              

        return value;
    }
};

// 2 version

// 3 version

// 4 version

// 5 version

int main([[maybe_unused]] int argc, [[maybe_unused]] char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::vector<int> a{ -1 };// { 4, 1, 2, 1, 2 };
    std::cout << s.singleNumber(a) << std::endl;

    return EXIT_SUCCESS;
}
