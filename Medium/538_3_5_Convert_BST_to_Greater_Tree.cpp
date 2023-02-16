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
//    void convert(TreeNode* node, int& greaterSum, int& prev, int& count)
//    {
//        if (node == nullptr)
//            return;
//        convert(node->right, greaterSum, prev, count);
//        if (node->val == prev)
//            count++;
//        else
//        {
//            greaterSum += prev * count;
//            count = 1;
//            prev = node->val;
//        }
//        node->val += greaterSum;
//        convert(node->left, greaterSum, prev, count);
//    }
//
//public:
//    TreeNode* convertBST(TreeNode* root) 
//    {
//        int greaterSum = 0;
//        int prev = 0;
//        int count = 0;
//        convert(root, greaterSum, prev, count);
//        return root;
//    }
//};

// 2 version
class Solution
{
    TreeNode * convert(TreeNode* node, int& greaterSum, int& prev, int& count)
    {
        if (node == nullptr)
            return nullptr;
        TreeNode* newNode = new TreeNode(0);
        newNode->right = convert(node->right, greaterSum, prev, count);
        if (node->val == prev)
            count++;
        else
        {
            greaterSum += prev * count;
            count = 1;
            prev = node->val;
        }
        newNode->val =  node->val + greaterSum;
        newNode->left = convert(node->left, greaterSum, prev, count);
        return newNode;
    }

public:
    TreeNode* convertBST(TreeNode* root)
    {
        int greaterSum = 0;
        int prev = 0;
        int count = 0;
        return convert(root, greaterSum, prev, count);        
    }
};
// 3 version

// 4 version

// 5 version

// 5 version


int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    std::ios_base::sync_with_stdio(false);    
    std::cin.tie(nullptr);

//    Solution s;
    /*std::vector<int> a{ 4, 1, 2, 1, 2 };
    std::cout << s.singleNumber(a) << std::endl;*/

    return EXIT_SUCCESS;
}
