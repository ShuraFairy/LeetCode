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
class Solution 
{
    bool canSubstract(int a, int b)
    {
        return (b >= 0 && a >= INT_MIN + b) ||
               (b < 0 && a <= INT_MAX + b);
    }

public:
    std::vector<int> twoSum(const std::vector<int>& a, int target) 
    {
        std::unordered_map<int, int> valueToIndex;
        for (int i = 0; i < (int)a.size(); ++i)
        {   
            if (canSubstract(target, a[i]))
            {
                auto it = valueToIndex.find(target - a[i]);
                if (it != valueToIndex.end())
                    return { it->second, i };
            }
            valueToIndex[a[i]] = i;
        }
        throw std::invalid_argument("sum not found");
    }
};

// 2 version
//class Solution {
//public:
//    std::vector<int> twoSum(const std::vector<int>& a, int target) 
//    {
//        std::unordered_map<int, int> valueToIndex;
//        for (int i = 0; i < (int)a.size(); ++i)
//        {            
//            auto it = valueToIndex.find(target - a[i]);
//            if (it != valueToIndex.end())
//                return { it->second, i };
//            valueToIndex[a[i]] = i;
//        }
//        throw std::invalid_argument("sum not found");
//    }
//};
// 
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
