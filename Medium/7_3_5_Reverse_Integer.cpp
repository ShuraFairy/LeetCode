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

// 1 version
//class Solution 
//{
//public:
//    int reverse(int x) 
//    {
//        int sign = 0;
//        if (x >= 0)
//            sign = 1;
//        else
//            sign = -1;
//        std::string s = std::to_string(std::abs((long long)x));
//        std::reverse(s.begin(), s.end());
//        long long value = std::stoll(s) * sign;
//        if (INT_MIN <= value && value <= INT_MAX)
//            return (int)value;
//        else
//            return 0;
//    }
//};

// 2 version
class Solution
{
public:
    int reverse(int x)
    {
        if (x == INT_MIN)
            return 0;

        int sign = 0;
        if (x >= 0)
            sign = 1;
        else
        {
            sign = -1;
            x = -x;
        }
        int res = 0;
        while (x > 0)
        {
            int d = x % 10;            
            x /= 10;
            if (res < INT_MAX / 10 || res == INT_MAX / 10 && d < INT_MAX % 10)
                res = res * 10 + d;
            else
                return 0;
        }
        return res * sign;
    }
};
 
// 3 version

// 4 version

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
