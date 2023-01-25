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
//class Solution 
//{
//public:
//    std::vector<int> twoSum(std::vector<int>& a, int target) 
//    {
//        std::vector<int>::size_type size = a.size();
//        for (int i = 0; static_cast<int>(size); ++i)
//        {
//            for (int j = i + 1; j < static_cast<int>(size); ++j)
//            {
//                if (a[i] + a[j] == target)
//                    return { i + 1, j + 1 };
//            }
//        }
//        throw std::invalid_argument("invalid");
//    }
//};

// 2 version
//class Solution
//{
//public:
//    std::vector<int> twoSum(std::vector<int>& a, int target)
//    {
//        std::vector<int>::size_type size = a.size();
//        std::unordered_map<int, int> valueToIndex;
//        for (int i = 0; static_cast<int>(size); ++i)
//        {
//            auto it = valueToIndex.find(target - a[i]);
//            if (it != valueToIndex.end())
//            {
//                return { it->second + 1, i + 1 };
//            }
//            valueToIndex[a[i]] = i;
//        }
//        
//        throw std::invalid_argument("invalid");
//    }
//};

// 3 version
//class Solution
//{
//public:
//    std::vector<int> twoSum(std::vector<int>& a, int target)
//    {
//        std::vector<int>::size_type size = a.size();
//       
//        for (int i = 0; static_cast<int>(size); ++i)
//        {
//            int j = static_cast<int>(std::upper_bound(a.begin(), a.end(), target - a[i]) - a.begin()) - 1;
//            assert(j > i);
//            if (a[j] == target - a[i])
//                return { i + 1, j + 1 };
//        }
//
//        throw std::invalid_argument("invalid");
//    }
//};

// 4 version
//class Solution
//{
//public:
//    std::vector<int> twoSum(std::vector<int>& a, int target)
//    {
//        std::vector<int>::size_type size = a.size();
//        int j = static_cast<int>(size) - 1;
//        for (int i = 0; i < static_cast<int>(size); ++i)
//        {
//            while (j >= 0 && a[i] + a[j] > target)
//                j--;
//            assert(i < j);
//            if (a[i] + a[j] == target)
//                return { i + 1, j + 1 };
//        }
//
//        throw std::invalid_argument("invalid");
//    }
//};

// 5 version
class Solution
{
    bool sumGreater(int a, int b, int c)    // a + b > c
    {
        if (b > 0 && a > INT_MAX - b)
            return true;
        if (b < 0 && a < INT_MIN - b)
            return false;
        return a + b > c;
    }

    bool sumEquals(int a, int b, int c)    // a + b == c
    {
        if (b > 0 && a > INT_MAX - b)
            return false;
        if (b < 0 && a < INT_MIN - b)
            return false;
        return a + b == c;
    }

public:
    std::vector<int> twoSum(std::vector<int>& a, int target)
    {
        std::vector<int>::size_type size = a.size();
        int j = static_cast<int>(size) - 1;
        for (int i = 0; i < static_cast<int>(size); ++i)
        {
            while (j >= 0 && sumGreater(a[i], a[j], target))
                j--;
            assert(i < j);
            if (sumEquals(a[i], a[j], target))
                return { i + 1, j + 1 };
        }

        throw std::invalid_argument("invalid");
    }
};

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
