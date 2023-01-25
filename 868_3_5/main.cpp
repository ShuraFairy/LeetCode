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
//class Solution {
//public:
//    int binaryGap(int n) {
//        while ((n & 1) == 0)
//        {
//            n >>= 1;
//        }
//        n >>= 1;
//        int ans = 0;
//        int lastDistance = 1;
//        while (n != 0)
//        {
//            int bit = n & 1;
//            n >>= 1;
//            if (bit == 1)
//            {
//                ans = std::max(ans, lastDistance);
//                lastDistance = 1;
//            }
//            else
//            {
//                assert(bit == 0);
//                lastDistance++;
//            }
//        }
//
//        return ans;
//    }
//};

// 2 version
//class Solution {
//public:
//    int binaryGap(int n) 
//    {
//        if ((n & (n - 1)) == 0) // степень 2
//        {
//            return 0;
//        }
//        n |= n - 1;
//        int ans = 1;
//        while((n & (n+1)) != 0) 
//        { 
//            n |= n >> 1;
//            ans++;
//        }
//        return ans;
//    }
//};

// 3 version
class Solution 
{
public:
    int binaryGap(int n) 
    {
        if ((n & (n - 1)) == 0) // степень 2
            return 0;
        n |= n - 1;        
        if ((n & (n + 1)) == 0)
            return 1;
        int shift = 1;
        int ans = 1;
        while (true)
        {
            int t = n | (n >> shift);
            if ((t & (t + 1)) != 0)
            {
                n = t;
                ans += shift;
                shift <<= 1;
            }
            else
                break;
        }
        int left = 0;
        int right = shift;
        while (left + 1 < right)
        {
            int mid = (left + right) >> 1;
            int t = n | (n >> mid);
            if ((t & (t + 1)) != 0)
                left = mid;
            else
                right = mid;
        }
        return ans + right;
    }
};

// 4 version

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
