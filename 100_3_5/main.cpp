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
//    bool isSameTree(TreeNode* p, TreeNode* q) 
//    {
//        if (p == nullptr && q == nullptr)
//            return true;
//        return p != nullptr && q != nullptr && p->val == q->val && isSameTree(p->left, q->left)
//            && isSameTree(p->right, q->right);
//    }
//};

// 2 version
class Solution
{
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (p == nullptr && q == nullptr)
            return true;

        std::stack<std::pair< TreeNode*, TreeNode*>> st;
        st.push(std::make_pair(p, q));
        while (!st.empty())
        {
            auto pair = st.top();
            st.pop();
            if (pair.first == nullptr && pair.second == nullptr)
                continue;
            if (pair.first == nullptr || pair.second == nullptr)
                return false;
            if (pair.first->val != pair.second->val)
                return false;
            st.push(std::make_pair(pair.first->left, pair.second->left));
            st.push(std::make_pair(pair.first->right, pair.second->right));
        }
        return true;
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

    Solution s;
    /*std::vector<int> a{ 4, 1, 2, 1, 2 };
    std::cout << s.singleNumber(a) << std::endl;*/

    return EXIT_SUCCESS;
}
