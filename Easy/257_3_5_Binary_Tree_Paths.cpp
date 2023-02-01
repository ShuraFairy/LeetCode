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
//    void traversal(TreeNode* node, std::string path, std::vector<std::string> & ans)
//    {
//        if (node == nullptr)
//            return;
//        if (node->left == nullptr && node->right == nullptr)
//        {
//            ans.push_back(path + std::to_string(node->val));
//            return;
//        }
//        path += std::to_string(node->val) + "->";
//        traversal(node->left, path, ans);
//        traversal(node->right, path, ans);
//    }
//public:
//    std::vector<std::string> binaryTreePaths(TreeNode* root) 
//    {
//        std::vector<std::string> ans;
//        traversal(root, "", ans);
//        return ans;
//    }
//};

// 2 version
class Solution
{
    void traversal(TreeNode* node, std::vector<char> &path, std::vector<std::string>& ans)
    {
        if (node == nullptr)
            return;
        size_t oldPathSize = path.size();
        for (char c : std::to_string(node->val))
            path.push_back(c);
        if (node->left == nullptr && node->right == nullptr)
        {
            ans.emplace_back(path.begin(), path.end());            
        }
        else
        {
            path.push_back('-');
            path.push_back('>');
            if (node->left != nullptr)
                traversal(node->left, path, ans);
            if (node->right != nullptr)
                traversal(node->right, path, ans);
        }
        while (path.size() > oldPathSize)
        {
            path.pop_back();
        }
    }
public:
    std::vector<std::string> binaryTreePaths(TreeNode* root)
    {
        std::vector<std::string> ans;
        std::vector<char> path;
        traversal(root, path, ans);
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

    //Solution s;
    /*std::vector<int> a{ 4, 1, 2, 1, 2 };
    std::cout << s.singleNumber(a) << std::endl;*/

    return EXIT_SUCCESS;
}
