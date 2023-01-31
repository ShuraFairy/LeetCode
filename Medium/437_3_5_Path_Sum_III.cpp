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
//    void visitBottom(TreeNode * node, int targetSum, long long sum, int& ans)
//    {
//        if (node == nullptr)
//            return;
//        sum += node->val;
//
//        if (sum == targetSum)
//            ++ans;
//        visitBottom(node->left, targetSum, sum, ans);
//        visitBottom(node->right, targetSum, sum, ans);
//    }
//
//    void visitTop(TreeNode* node, int targetSum, int & ans)
//    {
//        if (node == nullptr)
//            return;
//        visitBottom(node, targetSum, 0, ans);
//        visitTop(node->left, targetSum, ans);
//        visitTop(node->right, targetSum, ans);
//    }
//
//public:
//    int pathSum(TreeNode* root, int targetSum) 
//    {
//        if (targetSum < -1000 * 1000 * 1000 || targetSum > 1000 * 1000 * 1000)
//            return 0;
//        int ans = 0;
//        visitTop(root, targetSum, ans);
//        return ans;
//    }
//};

// 2 version
class Solution
{
    int countPaths(TreeNode* node, std::unordered_map<long long, int>& count,
        long long prefixSum, int targetSum)
    {
        if (node == nullptr)
            return 0;
        count[prefixSum]++;
        prefixSum += node->val;
        int ans = count[prefixSum - targetSum] +
            countPaths(node->left, count, prefixSum, targetSum) +
            countPaths(node->right, count, prefixSum, targetSum);
        prefixSum -= node->val;
        count[prefixSum]--;
        return ans;
    }

public:
    int pathSum(TreeNode* root, int targetSum)
    {
        if (targetSum < -1000 * 1000 * 1000 || targetSum > 1000 * 1000 * 1000)
            return 0;
        std::unordered_map<long long, int> count; // prefix sum -> count
        return countPaths(root, count, 0, targetSum);
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
