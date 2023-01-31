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
 
// 1 version
//class Solution 
//{
//public:
//    int maxSubArray(const std::vector<int>& a) 
//    {
//        // алгоритм Кадана
//        int maxEndsHere = a[0];
//        int totalMax = a[0];
//        for (size_t i = 1; i < a.size(); ++i)
//        {
//            maxEndsHere = std::max(maxEndsHere + a[i], a[i]);
//            totalMax = std::max(totalMax, maxEndsHere);
//        }
//        return totalMax;
//    }
//};

// 2 version
class Solution
{
    struct Stat
    {
        int maxSubstrSum;
        int maxPrefixSum;   // non-empty
        int maxSuffixSum;   // non-empty
        int sum;
    };

    Stat maxSubArray(const std::vector<int>& a, size_t first, size_t after)
    {
        assert(after > first);
        if (first + 1 == after)
            return Stat{ a[first], a[first], a[first], a[first] };
        size_t size = after - first;
        Stat half1 = maxSubArray(a, first, first + size / 2);
        Stat half2 = maxSubArray(a, first + size / 2, after);
        return Stat{
            std::max({
                half1.maxSubstrSum,
                half2.maxSubstrSum,
                half1.maxSuffixSum + half2.maxPrefixSum
                }),
            std::max(half1.maxPrefixSum, half1.sum + half2.maxPrefixSum),
            std::max(half2.maxSuffixSum, half2.sum + half1.maxSuffixSum),
            half1.sum + half2.sum
        };
    }

public:
    int maxSubArray(const std::vector<int>& a)
    {        
        return maxSubArray(a, 0, a.size()).maxSubstrSum;
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

//    Solution s;
    std::vector<int> a{ 0, 0, 2, 1 };
    std::vector<int> ans;
//    ans = s.addToArrayForm(a, 34);

    return EXIT_SUCCESS;
}
