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

// my version
//class Solution 
//{
//public:
//    int findComplement(int num) 
//    {
//        std::array<int, 31> arr;
//        for (int i = 0; i < 31; ++i)
//            arr[i] = 0;
//
//        int count = 0;
//        while(num > 0)
//        {
//            if ((num & 0x1) == 1)
//                arr[count] = 1;
//            num = num >> 1;
//            count++;
//        }
//        int result = 0;
//        for (int i = 0; i < count; ++i)
//        {
//            if (arr[i] == 0)
//                result += pow(2, i);            
//        }
//
//        return result;
//    }
//};


// 1 version
//class Solution 
//{
//public:
//    int findComplement(int num) 
//    {
//        int ans = 0;
//        int mask = 1;
//        while (num > 0)
//        {
//            if ((num & mask) == 0)
//                ans |= mask;
//            else
//                num ^= mask;
//            mask <<= 1;
//        }
//        return ans;
//    }
//};

// 2 version
//class Solution
//{
//public:
//    int findComplement(int num)
//    {
//        int left = 0;
//        int right = 31;
//        while (right > left + 1)
//        {
//            int mid = (left + right) >> 1;
//            if ((1 << mid) > num)
//                right = mid;
//            else
//                left = mid;
//        }
//        int mask = (1 << left) + ((1 << left) - 1);
//        return num ^ mask;
//    }
//};

// 3 version
class Solution
{
public:
    int findComplement(int num)
    {
        int mask = num;
        mask |= mask >> 1;
        mask |= mask >> 2;
        mask |= mask >> 4;
        mask |= mask >> 8;
        mask |= mask >> 16;
        
        return num ^ mask;
    }
};

// 4 version

// 5 version

int main([[maybe_unused]] int argc, [[maybe_unused]] char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::cout << s.findComplement(5) << std::endl;

    return EXIT_SUCCESS;
}
