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
#include <stack>
#include <unordered_map>

const int FASTIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

// 1 version
//class Solution 
//{
//public:
//    bool hasAlternatingBits(int n) 
//    {
//        int prev = (n & 1);
//        n >>= 1;
//        while (n > 0)
//        {
//            int cur = n & 1;
//            if (cur == prev)
//                return false;
//            n >>= 1;
//            prev = cur;
//        }
//        return true;
//    }
//};

// 2 version
//class Solution 
//{
//public:
//    bool hasAlternatingBits(int n) 
//    {
//        int last = n & 3;
//        if (last != 1 && last != 2)
//            return false;
//        n >>= 2;
//        while (n > 0)
//        {
//            if ((n & 3) != last)
//                return false;
//            n >>= 2;
//        }
//        return true;
//    }
//};

// 3 version
//class Solution 
//{
//public:
//    bool hasAlternatingBits(int n) 
//    {
//        int pow2 = n - (n >> 2);
//        return (pow2 & (pow2 - 1)) == 0;
//    }
//};

// 4 version
class Solution 
{
public:
    bool hasAlternatingBits(unsigned int n) 
    {
        unsigned int ones = n ^ (n >> 1);
        return (ones & (ones + 1)) == 0;
    }
};

// 5 version

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    std::ios_base::sync_with_stdio(false);    
    std::cin.tie(nullptr);

    Solution s;
    /*std::vector<int> a{ 4, 1, 2, 1, 2 };
    std::cout << s.singleNumber(a) << std::endl;*/

    return EXIT_SUCCESS;
}
