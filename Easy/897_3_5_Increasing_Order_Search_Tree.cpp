#include <ios>
#include <iostream>
#include <vector>
#include <cassert>
#include <type_traits>
#include <tuple>
#include <deque>
#include <queue>

const int FASTIO = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

// 1 version

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
 
//class Solution 
//{
//    void traversal(TreeNode* node, TreeNode*& result)
//    {
//        if (node == nullptr)
//            return;
//        traversal(node->right, result);
//        node->right = result;
//        result = node;        
//        traversal(node->left, result);
//        node->left = nullptr;
//    }
//
//public:
//    TreeNode* increasingBST(TreeNode* root) 
//    {
//        TreeNode* result = nullptr;
//        traversal(root, result);
//
//        return result;
//    }
//};

// 2 version
class Solution 
{
public:
    TreeNode* increasingBST(TreeNode* root) 
    {
        TreeNode* current = root;
        TreeNode* parent  = nullptr;
        TreeNode* result  = nullptr;
        while (true)
        {
            if (current == nullptr)
            {
                if (current == nullptr && parent == nullptr)
                {
                    return result;
                }
                else                 
                {
                    assert(parent != nullptr);
                    current = parent;
                    parent = parent->right;
                    current->right = nullptr;
                    continue;
                }
            }
            else
            {
                assert(current != nullptr);
                if (current->right != nullptr)
                {
                    TreeNode* temp = current->right;
                    current->right = parent;
                    parent = current;
                    current = temp;
                }
                else
                {
                    assert(current->right == nullptr);
                    current->right = result;
                    result = current;
                    current = current->left;
                    result->left = nullptr;
                }
            }
        }
    }
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    //std::vector<int> v{ 0,10,5,2 };//{ 0,2,1,0 };
    //Solution s;
    //std::cout << s.peakIndexInMountainArray(v) << std::endl;

	return EXIT_SUCCESS;
}
