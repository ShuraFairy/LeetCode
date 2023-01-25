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
//    int next(int n)
//    {
//        int sum = 0;
//        while (n > 0)
//        {
//            int d = n % 10;
//            n /= 10;
//            sum += d * d;
//        }
//        return sum;
//    }
//
//public:
//    bool isHappy(int n) 
//    {
//        std::unordered_set<int> visited;
//        while (true)
//        {
//            if (n == 1)
//                return true;
//            visited.insert(n);
//            n = next(n);
//            if (visited.count(n))
//                return false;
//        }
//    }
//};

// 2 version
class Solution
{
    int next(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int d = n % 10;
            n /= 10;
            sum += d * d;
        }
        return sum;
    }

public:
    bool isHappy(int n)
    {
        int slow = n;
        int fast = n;
        while (true)
        {            
            slow = next(slow);
            fast = next(next(fast));
            if (fast == 1)
                return true;
            if (fast == slow)
                return false;
        }
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

    //Solution s;
    /*std::vector<int> a{ 4, 1, 2, 1, 2 };
    std::cout << s.singleNumber(a) << std::endl;*/

    return EXIT_SUCCESS;
}
