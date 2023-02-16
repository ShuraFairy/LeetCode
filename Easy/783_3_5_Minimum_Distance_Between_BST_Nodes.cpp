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
//    void traversal(TreeNode * node, int & prev, bool & prevFilled, int & ans, bool &ansFilled)
//    {
//        if (node == nullptr)
//            return;
//        traversal(node->left, prev, prevFilled, ans, ansFilled);
//        if (prevFilled)
//        {
//            int diff = node->val - prev;
//            ans = std::min(ans, diff);
//            ansFilled = true;
//        }
//        prev = node->val;
//        prevFilled = true;
//        traversal(node->right, prev, prevFilled, ans, ansFilled);
//    }
//
//public:
//    int minDiffInBST(TreeNode* root) 
//    {        
//        int prev = 0;
//        bool prevFilled = false;
//        int ans = INT_MAX;
//        bool ansFilled = false;
//        traversal(root, prev, prevFilled, ans, ansFilled);
//        if (ansFilled == false)
//            throw std::overflow_error("Answer greater then INT_MAX");
//        return ans;
//    }
//};

// 2 version
class Solution
{
    void traversal(TreeNode* node, int& prev, bool& prevFilled, int& ans, bool& ansFilled)
    {
        if (node == nullptr)
            return;
        traversal(node->left, prev, prevFilled, ans, ansFilled);
        if (prevFilled)
        {
            assert(node->val > prev);
            if (prev >= 0 || node->val <= INT_MAX + prev)
            {
                int diff = node->val - prev;
                ans = std::min(ans, diff);
                ansFilled = true;
            }
        }
        prev = node->val;
        prevFilled = true;
        traversal(node->right, prev, prevFilled, ans, ansFilled);
    }

public:
    int minDiffInBST(TreeNode* root)
    {
        int prev = 0;
        bool prevFilled = false;
        int ans = INT_MAX;
        bool ansFilled = false;
        traversal(root, prev, prevFilled, ans, ansFilled);
        if (ansFilled == false)
            throw std::overflow_error("Answer greater then INT_MAX");
        return ans;
    }
};

// 3 version

// 4 version

// 5 version

// 6 version


int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    std::ios_base::sync_with_stdio(false);    
    std::cin.tie(nullptr);

//    Solution s;
    /*std::vector<int> a{ 4, 1, 2, 1, 2 };
    std::cout << s.singleNumber(a) << std::endl;*/

    return EXIT_SUCCESS;
}
