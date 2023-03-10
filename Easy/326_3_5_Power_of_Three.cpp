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
//public:
//    bool isPowerOfThree(int n) 
//    {
//        return n > 0 && 1'162'261'467 % n == 0;   // 3^19
//    }
//};

// 2 version
//class Solution
//{
//public:
//    bool isPowerOfThree(int n)
//    {
//        if (n <= 0)
//            return false;
//        while (n % 3 == 0)
//            n /= 3;
//        return n == 1;
//    }
//};
 
// 3 version
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n <= 0)
            return false;
        for (int d : {43'046'721, 6'561, 81, 9, 3})
        {
            if (n % d == 0)
                n /= d;
        }
        return n == 1;
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

//    Solution s;
    std::vector<int> a{ 0, 0, 2, 1 };
    std::vector<int> ans;
//    ans = s.addToArrayForm(a, 34);
//    std::cout << s.isPowerOfTwo(1) << std::endl;
//    std::cout << s.isPowerOfTwo(16) << std::endl;
//    std::cout << s.isPowerOfTwo(3) << std::endl;

    return EXIT_SUCCESS;
}
