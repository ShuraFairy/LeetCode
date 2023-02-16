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

// my version

// 1 version
//class Solution 
//{
//    int getHeight(TreeNode* node)
//    {
//        if (node == nullptr)
//            return 0;
//        int leftH = getHeight(node->left);
//        if (leftH == -1)
//            return -1;
//        int rightH = getHeight(node->right);
//        if (rightH == -1)
//            return -1;
//        if (std::abs(leftH - rightH) > 1)
//            return -1;
//        else
//            return std::max(leftH, rightH) + 1;
//    }
//
//public:
//    bool isBalanced(TreeNode* root) 
//    {
//        return getHeight(root) != -1;
//    }
//};

// 2 version
//class Solution
//{
//    int getHeight(TreeNode* node)
//    {
//        if (node == nullptr)
//            return 0;
//        return std::max(getHeight(node->left), getHeight(node->right)) + 1;
//    }
//
//public:
//    bool isBalanced(TreeNode* root)
//    {
//        if (root == nullptr)
//            return true;
//        return isBalanced(root->left) && isBalanced(root->right)
//            && std::abs(getHeight(root->left) - getHeight(root->right)) <= 1;
//    }
//};
 
// 3 version
//class Solution
//{
//    int getHeight(TreeNode* node)
//    {
//        if (node == nullptr)
//            return 0;
//        return std::max(getHeight(node->left), getHeight(node->right)) + 1;
//    }
//
//public:
//    bool isBalanced(TreeNode* root)
//    {
//        if (root == nullptr)
//            return true;
//        return isBalanced(root->left) & isBalanced(root->right)
//            & std::abs(getHeight(root->left) - getHeight(root->right)) <= 1;
//    }
//};

// 4 version
class Solution
{
    int getHeight(TreeNode* node)
    {
        if (node == nullptr)
            return 0;
        return std::max(getHeight(node->left), getHeight(node->right)) + 1;
    }

public:
    bool isBalanced(TreeNode* root)
    {
        if (root == nullptr)
            return true;
        return std::abs(getHeight(root->left) - getHeight(root->right)) <= 1 &&
            isBalanced(root->left) && isBalanced(root->right);
    }
};

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
//    std::cout << s.isPowerOfTwo(1) << std::endl;
//    std::cout << s.isPowerOfTwo(16) << std::endl;
//    std::cout << s.isPowerOfTwo(3) << std::endl;

    return EXIT_SUCCESS;
}
