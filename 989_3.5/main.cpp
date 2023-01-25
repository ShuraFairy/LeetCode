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
class Solution 
{
    size_t getLen(int n)
    {
        assert(n > 0);
        int ans = 0;
        while (n > 0)
        {
            ans++;
            n /= 10;
        }
        return ans;
    }

public:
    std::vector<int> addToArrayForm(std::vector<int>& a, int k) 
    {
        for (size_t i = a.size(); i-- > 0 && k > 0;)
        {
            k += a[i];
            a[i] = k % 10;
            k /= 10;
        }
        if (k > 0)
        {
            size_t len = getLen(k);
            a.insert(a.begin(), len, 0);
            for (size_t i = len; i-- > 0; )
            {
                a[i] = k % 10;
                k /= 10;
            }
        }
        return std::move(a);
    }
};

// 2 version
 
// 3 version

// 4 version

// 5 version

// 6 version

// 7 version

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    std::ios_base::sync_with_stdio(false);    
    std::cin.tie(nullptr);

    Solution s;
    std::vector<int> a{ 0, 0, 2, 1 };
    std::vector<int> ans;
//    ans = s.addToArrayForm(a, 34);

    return EXIT_SUCCESS;
}
