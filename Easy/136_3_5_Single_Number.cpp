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
//class Solution {
//public:
//    int singleNumber(std::vector<int>& nums) {
//        int ans = 0;
//
//        for (int x : nums)
//        {
//            ans ^= x;
//        }
//
//        return ans;
//    }
//};

// 2 version
class Solution
{
    static const int EQUAL_COUNT = 2;

public:
    int singleNumber(const std::vector<int>& nums)
    {
        const int INT_BIT_SIZE = sizeof(int) * 8;
        size_t countOnes[INT_BIT_SIZE] = {};
        for (unsigned int x : nums)
        {
            for (int bit = 0; bit < INT_BIT_SIZE; ++bit)
            {
                countOnes[bit] += x & 1;
                x >>= 1;
            }
        }
        unsigned int ans = 0;
        for (int bit = 0; bit < INT_BIT_SIZE; ++bit)
        {
            ans |= (unsigned int)(countOnes[bit] % EQUAL_COUNT) << bit;
        }
        return ans;
    }
};

// 3 version

// 4 version

// 5 version

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::vector<int> a{ 4, 1, 2, 1, 2 };
    std::cout << s.singleNumber(a) << std::endl;

    return EXIT_SUCCESS;
}
