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
//    bool rotateString(const std::string & a, const std::string & b) 
//    {
//        if (a == b)
//            return true;
//        if (a.size() != b.size()) 
//            return false;
//        int n = static_cast<int>(a.size());
//        for (int startA = 1; startA < n; ++startA)
//        {
//            bool good = true;
//            for (int indexB = 0; indexB < n; ++indexB)
//            {
//                int indexA = (startA + indexB) % n;
//                if (a[indexA] != b[indexB])
//                {
//                    good = false;
//                    break;
//                }
//            }
//            if (good)
//                return true;
//        }
//        return false;
//    }
//};

// 2 version
//class Solution
//{
//public:
//    bool rotateString(const std::string& a, const std::string& b)
//    {
//        if (a == b)
//            return true;
//        if (a.size() != b.size())
//            return false;
//        int n = static_cast<int>(a.size());
//        for (int startA = 1; startA < n; ++startA)
//        {
//            bool good = true;
//            for (int indexA = startA; indexA < n; ++indexA)
//            {
//                int indexB = indexA - startA;
//                if (a[indexA] != b[indexB])
//                {
//                    good = false;
//                    break;
//                }
//            }
//            if (good)
//            {
//                for (int indexA = 0; indexA < startA; ++indexA)
//                {
//                    int indexB = n - startA + indexA;
//                    if (a[indexA] != b[indexB])
//                    {
//                        good = false;
//                        break;
//                    }
//                }
//                if (good)
//                    return true;
//            }
//        }
//        return false;
//    }
//};

// 3 version
//class Solution
//{
//public:
//    bool rotateString(const std::string& a, const std::string& b)
//    {
//        return a.size() == b.size() && (a + a).find(b) != std::string::npos;        
//    }
//};

// 4 version
//class Solution
//{
//public:
//    bool rotateString(const std::string& a, const std::string& b)
//    {
//        if (a == b)
//            return true;
//        if (a.size() != b.size())
//            return false;
//        
//        size_t n = b.size();
//        std::vector<size_t> prefix(1 + n, 0);    // [len] -> len
//        size_t len = 0;
//        for (size_t i = 1; i < n; ++i)
//        {
//            while (true)
//            {
//                if (b[len] == b[i])
//                {
//                    len++;
//                    break;
//                }
//                if (len == 0)
//                    break;
//                len = prefix[len];
//            }
//            prefix[i + 1] = len;
//        }
//        len = 0;
//        for (size_t i = 0; i < 2 * n; ++i)
//        {
//            while (true)
//            {
//                if (b[len] == a[i % n])
//                {
//                    len++;
//                    break;
//                }
//                if (len == 0)
//                    break;
//                len = prefix[len];
//            }
//            if (len == n)
//                return true;
//        }
//        return false;
//    }
//};

// 5 version
class Solution
{
public:
    bool rotateString(const std::string& a, const std::string& b)
    {
        if (a == b)
            return true;
        if (a.size() != b.size())
            return false;

        size_t n = b.size();
        std::vector<size_t> prefix(1 + n, 0);    // [len] -> len
        size_t len = 0;
        for (size_t i = 1; i < n; ++i)
        {
            while (true)
            {
                if (b[len] == b[i])
                {
                    len++;
                    break;
                }
                if (len == 0)
                    break;
                len = prefix[len];
            }
            prefix[i + 1] = len;
        }
        len = 0;
        for (size_t i = 0; i < n; ++i)
        {
            while (true)
            {
                if (b[len] == a[i])
                {
                    len++;
                    break;
                }
                if (len == 0)
                    break;
                len = prefix[len];
            }
            if (len == n)
                return true;
        }
        for (size_t i = 0; i < n; ++i)
        {
            while (true)
            {
                if (b[len] == a[i])
                {
                    len++;
                    break;
                }
                if (len == 0)
                    break;
                len = prefix[len];
            }
            if (len == n)
                return true;
        }
        return false;
    }
};

// 6 version


int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    std::ios_base::sync_with_stdio(false);    
    std::cin.tie(nullptr);

//    Solution s;
    /*std::vector<int> a{ 4, 1, 2, 1, 2 };
    std::cout << s.singleNumber(a) << std::endl;*/

    return EXIT_SUCCESS;
}
