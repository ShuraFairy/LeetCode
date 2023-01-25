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
public:
    bool isLongPressedName(const std::string & name, const std::string typed) 
    {
        size_t iName = 0;
        size_t iTyped = 0;
        while (true)
        {
            if (iName == name.size() && iTyped == typed.size())
                return true;
            if (iName == name.size() || iTyped == typed.size())
                return false;
            if (name[iName] != typed[iTyped])
                return false;
            char c = name[iName];
            size_t nameGroupSize = 0;
            size_t typedGroupSize = 0;
            while (iName < name.size() && name[iName] == c)
            {
                iName++;
                nameGroupSize++;
            }
            while (iTyped < typed.size() && typed[iTyped] == c)
            {
                iTyped++;
                typedGroupSize++;
            }
            if (typedGroupSize < nameGroupSize)
                return false;
        }
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
