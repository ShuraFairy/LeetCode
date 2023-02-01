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
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
//    {
//        assert(p != nullptr);
//        assert(q != nullptr);
//        while (true)
//        {
//            assert(root != nullptr);
//            if (p->val < root->val && q->val < root->val)
//                root = root->left;
//            else if (p->val > root->val && q->val > root->val)
//                root = root->right;
//            else
//                return root;
//        }
//    }
//};

// 2 version
//class Solution
//{
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
//    {
//        int pVal = p->val;
//        int qVal = q->val;
//        while (true)
//        {
//            int val = root->val;
//            if (pVal < val && qVal < val)
//                root = root->left;
//            else if (pVal > val && qVal > val)
//                root = root->right;
//            else
//                return root;
//        }
//    }
//};
 
// 3 version
class Solution
{
    TreeNode* lastCommon(const std::vector<TreeNode*> & v1, const std::vector<TreeNode*>& v2)
    {
        assert(!v1.empty() && !v2.empty() && v1[0] == v2[0]);
        int i = 0;
        while (i < (int)v1.size() && i < (int)v2.size() && v1[i] == v2[i])
            ++i;
        return v1[i - 1];
    }

    std::vector<TreeNode*> getPath(TreeNode* root, int val)
    {
        std::vector<TreeNode*> path;
        while (true)
        {
            path.push_back(root);
            if (val < root->val)
                root = root->left;
            else if (val > root->val)
                root = root->right;
            else
                return path;
        }
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        return lastCommon(getPath(root, p->val), getPath(root, q->val));
    }
};

// 4 version

// 5 version

// 6 version

// 7 version

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    std::ios_base::sync_with_stdio(false);    
    std::cin.tie(nullptr);

    //Solution s;
    /*std::vector<int> a{ 4, 1, 2, 1, 2 };
    std::cout << s.singleNumber(a) << std::endl;*/

    return EXIT_SUCCESS;
}
