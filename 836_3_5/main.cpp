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
struct Rect
{
    const int minX;
    const int minY;
    const int maxX;
    const int maxY;
    Rect(const std::vector<int>& r) : minX(r[0]), minY(r[1]), maxX(r[2]), maxY(r[3])
    {
        assert(minX <= maxX);
        assert(minY <= maxY);
    }
};
class Solution 
{
    bool isSegmentOverlap(int min1, int max1, int min2, int max2) const
    {
        return !(min1 >= max2 || min2 >= max1);
    }

public:
    bool isRectangleOverlap(const Rect & r1, const Rect& r2) const
    {
        return isSegmentOverlap(r1.minX, r1.maxX, r2.minX, r2.maxX) &&
               isSegmentOverlap(r1.minY, r1.maxY, r2.minY, r2.maxY);
    }

    bool isRectangleOverlap(std::vector<int>& rec1, std::vector<int>& rec2) const
    {
        return isRectangleOverlap(Rect(rec1), Rect(rec2));
    }
};

// 2 version

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
