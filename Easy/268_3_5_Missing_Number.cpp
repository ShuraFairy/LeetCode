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
//    int missingNumber(std::vector<int>& a) 
//    {
//        int n = static_cast<int>(a.size());
//        long long sum = n * (n + 1LL) / 2;
//        for (int v : a)
//            sum -= v;
//        return (int)sum;
//    }
//};

// 2 version
class Solution
{
public:
    int missingNumber(std::vector<int>& a)
    {
        int n = static_cast<int>(a.size());
        for (int i = 0; i < n; ++i)
        {
            while (a[i] != n && a[i] != i)
                std::swap(a[i], a[a[i]]);
        }
        for (int i = 0; i < n; ++i)
        {
            if (a[i] == n)
                return i;
        }
        return n;
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
