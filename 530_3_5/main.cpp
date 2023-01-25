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
class Solution 
{
    void traversal(TreeNode* node, int& minDiff, int& prev, bool& prevFilled)
    {
        if (node == nullptr)
            return;
        traversal(node->left, minDiff, prev, prevFilled);
        if (prevFilled)
            minDiff = std::min(minDiff, node->val - prev);
        prev = node->val;
        prevFilled = true;
        traversal(node->right, minDiff, prev, prevFilled);
    }

public:
    int getMinimumDifference(TreeNode* root) 
    {
        int minDiff = INT_MAX;
        int prev = 0;
        bool prevFilled = false;
        traversal(root, minDiff, prev, prevFilled);
        return minDiff;
    }
};

// 2 version

// 3 version

// 4 version

// 5 version

// 5 version


int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    std::ios_base::sync_with_stdio(false);    
    std::cin.tie(nullptr);

    Solution s;
    /*std::vector<int> a{ 4, 1, 2, 1, 2 };
    std::cout << s.singleNumber(a) << std::endl;*/

    return EXIT_SUCCESS;
}
