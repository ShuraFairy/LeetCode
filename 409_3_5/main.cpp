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
//    int longestPalindrome(const std::string & s) 
//    {
//        int count[1 + 'z'] = {};
//        for (char c : s)
//            count[c]++;
//        int even = 0;
//        int odd = 0;
//        for (int c = 'A'; c <= 'z'; ++c)
//        {
//            even += count[c] & (~1);
//            odd |= count[c] & 1;
//        }
//        return even + odd;
//    }
//};

// 2 version
//class Solution
//{
//public:
//    int longestPalindrome(const std::string& s)
//    {
//        int count[128] = {};
//        for (char c : s)
//            count[c]++;
//        int even = 0;
//        int odd = 0;
//        for (int c = 0; c < 128; ++c)
//        {
//            even += count[c] & (~1);
//            odd |= count[c] & 1;
//        }
//        return even + odd;
//    }
//};

// 3 version
class Solution
{
public:
    int longestPalindrome(const std::string& s)
    {
        std::unordered_map<char, int> count;
        for (char c : s)
            count[c]++;
        int even = 0;
        int odd = 0;
        for(const auto & kv : count)
        {
            int c = kv.first;
            even += count[c] & (~1);
            odd |= count[c] & 1;
        }
        return even + odd;
    }
};

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
