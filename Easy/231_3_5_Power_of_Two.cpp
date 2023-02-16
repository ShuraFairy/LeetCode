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
//class Solution 
//{
//public:
//    bool isPowerOfTwo(int n)
//    {
//        size_t _n = 0;
//        if (n > 0)
//            _n = n;
//        else
//            _n = static_cast<long long>(n) * -1;
//        int one = 0;
//        for (size_t i = 0; i < 32; ++i)
//        {
//            if ((_n & 1) == 1)
//                one++;
//            _n = _n >> 1;
//        }
//        if ((n > 0 && one == 1))
//            return true;
//        else
//            return false;
//    }
//};

// 1 version
//class Solution 
//{
//public:
//    bool isPowerOfTwo(int n)
//    {
//        return n > 0 && (n & (n - 1)) == 0;
//    }
//};

// 2 version
class Solution 
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n < 0) return false;
        size_t _n = n;        
        int one = 0;
        for (size_t i = 0; i < 32; ++i)
        {
            if ((_n & 1) == 1)
                one++;
            _n = _n >> 1;
        }
        if ((n > 0 && one == 1))
            return true;
        else
            return false;
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
//    std::cout << s.isPowerOfTwo(1) << std::endl;
//    std::cout << s.isPowerOfTwo(16) << std::endl;
//    std::cout << s.isPowerOfTwo(3) << std::endl;

    return EXIT_SUCCESS;
}
