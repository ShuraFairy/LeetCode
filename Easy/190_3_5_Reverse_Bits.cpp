#include <cstdio>   
#include <cstdlib> 
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
#include <unordered_set>
#include <random>
#include <set>
#include <string>

#pragma push_macro("assert")
#undef assert
#pragma pop_macro("assert")

const int FASTIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

// Definition for singly - linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}    
};

// Definition for a binary tree node.
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// my version
//class Solution
//{
//public:
//    uint32_t reverseBits(uint32_t n)
//    {
//        uint64_t res = 0;
//
//        for (size_t i = 0; i < 32; ++i)
//        {
//            if (n & 1)
//                res = res | 1;
//
//            res = res << 1;
//            n = n >> 1;
//        }
//        res = res >> 1;
//
//        return res;
//    }
//};

// 1 version
//class Solution 
//{
//public:
//    uint32_t reverseBits(uint32_t n) 
//    {
//        uint32_t ans = 0;
//        for (int i = 0; i < 32; ++i)
//        {
//            ans = ans * 2 + n % 2;
//            n /= 2;
//        }
//        return ans;
//    }
//};

// 2 version
//class Solution
//{
//public:
//    uint32_t reverseBits(uint32_t n)
//    {
//        uint32_t ans = 0;
//        for (int i = 0; i < 32; ++i)
//        {
//            ans = (ans << 1) | (n & 1);
//            n >>= 1;
//        }
//        return ans;
//    }
//};
 
// 3 version
//class Solution
//{
//public:
//    uint32_t reverseBits(uint32_t n)
//    {
//        {
//            //uint32_t hi = n & 0xFFFF0000;
//            //uint32_t lo = n & 0x0000FFFF;
//            n = (n >> 16) | (n << 16);
//        }
//        {
//            uint32_t hi = n & 0xFF00FF00;
//            uint32_t lo = n & 0x00FF00FF;
//            n = (hi >> 8) | (lo << 8);
//        }
//        {
//            uint32_t hi = n & 0xF0F0F0F0;
//            uint32_t lo = n & 0x0F0F0F0F;
//            n = (hi >> 4) | (lo << 4);
//        }
//        {
//            uint32_t hi = n & 0xCCCCCCCC;
//            uint32_t lo = n & 0x33333333;
//            n = (hi >> 2) | (lo << 2);
//        }
//        {
//            uint32_t hi = n & 0xAAAAAAAA;
//            uint32_t lo = n & 0x55555555;
//            n = (hi >> 1) | (lo << 1);
//        }
//        return n;
//    }
//};

// 4 version
class Solution
{
    static uint16_t reverse16[1 << 16];

public:
    Solution()
    {
        if (reverse16[1] == 0)
        {
            uint16_t reverse2[1 << 2] = { 0, 2, 1, 3 };
            uint16_t reverse4[1 << 4];
            for (int hi = 0; hi < (1 << 2); hi++)
            {
                for (int lo = 0; lo < (1 << 2); lo++)
                {
                    reverse4[(hi << 2) | lo] = (reverse2[lo] << 2) | reverse2[hi];
                }
            }
            uint16_t reverse8[1 << 8];
            for (int hi = 0; hi < (1 << 4); hi++)
            {
                for (int lo = 0; lo < (1 << 4); lo++)
                {
                    reverse8[(hi << 4) | lo] = (reverse4[lo] << 4) | reverse4[hi];
                }
            }
            for (int hi = 0; hi < (1 << 8); hi++)
            {
                for (int lo = 0; lo < (1 << 8); lo++)
                {
                    reverse16[(hi << 8) | lo] = (reverse8[lo] << 8) | reverse8[hi];
                }
            }
        }
    }

public:
    uint32_t reverseBits(uint32_t n)
    {
        return (reverse16[n & 0xFFFF] << 16 | reverse16[n >> 16]);
    }
};

uint16_t Solution::reverse16[1 << 16];

// 5 version

// 6 version

// 7 version

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    std::ios_base::sync_with_stdio(false);    
    std::cin.tie(nullptr);        

    Solution s;
    //std::cout << s.reverseBits(3) << std::endl;
    
    int* p1 = (int*)malloc(4 * sizeof(int));
    free(p1);    

    return EXIT_SUCCESS;
}
