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
//    int maxProfit(const std::vector<int>& a) 
//    {
//        int ans = 0;
//        for (int i = 0; i < (int)a.size(); ++i)
//        {
//            for (int j = i + 1; j < (int)a.size(); ++j)
//            {
//                ans = std::max(ans, a[j] - a[i]);
//            }
//        }
//        return ans;
//    }
//};

// 2 version
//class Solution
//{
//public:
//    int maxProfit(const std::vector<int>& a)
//    {
//        int ans = 0;
//        int prevMin = a[0];
//        for (int v : a)
//        {
//            ans = std::max(ans, v - prevMin);
//            prevMin = std::min(prevMin, v);
//        }
//        return ans;
//    }
//};

// 3 version
//class Solution
//{
//public:
//    int maxProfit(const std::vector<int>& a)
//    {
//        int ans = 0;
//        int prevMin = INT_MAX;
//        for (int v : a)
//        {
//            ans = std::max(ans, v - prevMin);
//            prevMin = std::min(prevMin, v);
//        }
//        return ans;
//    }
//};

// 4 version
//class Solution
//{
//public:
//    int maxProfit(const std::vector<int>& a)
//    {
//        int ans = 0;
//        int nextMax = 0;
//
//        for (int i = (int)a.size() - 1; i >= 0; i--)
//        {
//            int v = a[i];
//            ans = std::max(ans, nextMax - v);
//            nextMax = std::max(nextMax, v);
//        }
//                
//        return ans;
//    }
//};

// 5 version
class Solution
{
public:
    int maxProfit(const std::vector<int>& a)
    {
        int ans = 0;
        int nextMax = 0;

        for (int i = (int)a.size(); i-- > 0; )
        {
            int v = a[i];
            ans = std::max(ans, nextMax - v);
            nextMax = std::max(nextMax, v);
        }

        return ans;
    }
};

// 6 version


int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    std::ios_base::sync_with_stdio(false);    
    std::cin.tie(nullptr);

    //Solution s;
    /*std::vector<int> a{ 4, 1, 2, 1, 2 };
    std::cout << s.singleNumber(a) << std::endl;*/

    return EXIT_SUCCESS;
}
