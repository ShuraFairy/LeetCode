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
//    std::vector<char> norm(const std::string& s)
//    {
//        std::vector<char> t;
//        for (char c : s)
//        {
//            if (c == '#')
//            {
//                if (!t.empty())
//                    t.pop_back();
//            }
//            else
//            {
//                assert('a' <= c && c <= 'z');
//                t.push_back(c);
//            }
//        }
//        return t;
//    }
//
//public:
//    bool backspaceCompare(const std::string & s1, const std::string & s2) 
//    {
//        return norm(s1) == norm(s2);
//    }
//};

// 2 version
//class Solution
//{
//    void norm(std::string& s)
//    {
//        int dst = 0;
//        for (char c : s)
//        {
//            if (c == '#')
//            {
//                if (dst > 0)
//                    dst--;
//            }
//            else
//            {                
//                assert('a' <= c && c <= 'z');
//                s[dst] = c;
//                dst++;                
//            }
//        }
//        s.resize(dst);
//    }
//
//public:
//    bool backspaceCompare(std::string s1, std::string s2)
//    {
//        norm(s1);
//        norm(s2);
//        return s1 == s2;
//    }
//};
 
// 3 version
//class Solution
//{
//public:
//    bool backspaceCompare(const std::string & s1, const std::string & s2)
//    {
//        int i1 = (int)s1.size() - 1;
//        int i2 = (int)s2.size() - 1;
//
//        while (true)
//        {
//            {
//                int balance = 0;
//                while (true)
//                {
//                    if (i1 < 0)
//                        break;
//                    if (s1[i1] == '#')
//                        balance--;
//                    else
//                        balance++;
//                    if (balance > 0)
//                        break;
//                    i1--;
//                }
//            }
//            {
//                int balance = 0;
//                while (true)
//                {
//                    if (i2 < 0)
//                        break;
//                    if (s2[i2] == '#')
//                        balance--;
//                    else
//                        balance++;
//                    if (balance > 0)
//                        break;
//                    i2--;
//                }
//            }
//            if (i1 == -1 && i2 == -1)
//                return true;
//            if (i1 == -1 || i2 == -1)
//                return false;
//            if (s1[i1] != s2[i2])
//                return false;
//            i1--;
//            i2--;
//        }
//    }
//};

// 4 version
//class Solution
//{
//public:
//    bool backspaceCompare(const std::string& s1, const std::string& s2)
//    {
//        size_t i1 = s1.size();
//        size_t i2 = s2.size();
//
//        while (true)
//        {
//            {
//                int balance = 0;
//                while (true)
//                {
//                    if (i1 == 0)
//                        break;
//                    if (s1[i1 - 1] == '#')
//                        balance--;
//                    else
//                        balance++;
//                    if (balance > 0)
//                        break;
//                    i1--;
//                }
//            }
//            {
//                int balance = 0;
//                while (true)
//                {
//                    if (i2 == 0)
//                        break;
//                    if (s2[i2 - 1] == '#')
//                        balance--;
//                    else
//                        balance++;
//                    if (balance > 0)
//                        break;
//                    i2--;
//                }
//            }
//            if (i1 == 0 && i2 == 0)
//                return true;
//            if (i1 == 0 || i2 == 0)
//                return false;
//            if (s1[i1 - 1] != s2[i2 - 1])
//                return false;
//            i1--;
//            i2--;
//        }
//    }
//};


// 5 version
class Solution
{
public:
    bool backspaceCompare(const std::string& s1, const std::string& s2)
    {
        size_t i1 = s1.size();
        size_t i2 = s2.size();

        while (true)
        {
            {
                size_t letters = 0;
                size_t backspaces = 0;
                while (true)
                {
                    if (i1 == 0)
                        break;
                    if (s1[i1 - 1] == '#')
                        backspaces++;
                    else
                        letters++;
                    if (letters > backspaces)
                        break;
                    i1--;
                }
            }
            {
                size_t letters = 0;
                size_t backspaces = 0;
                while (true)
                {
                    if (i2 == 0)
                        break;
                    if (s2[i2 - 1] == '#')
                        backspaces++;
                    else
                        letters++;
                    if (letters > backspaces)
                        break;
                    i2--;
                }
            }
            if (i1 == 0 && i2 == 0)
                return true;
            if (i1 == 0 || i2 == 0)
                return false;
            if (s1[i1 - 1] != s2[i2 - 1])
                return false;
            i1--;
            i2--;
        }
    }
};

// 6 version

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    std::ios_base::sync_with_stdio(false);    
    std::cin.tie(nullptr);

    //Solution s;
    /*std::vector<int> a{ 4, 1, 2, 1, 2 };
    std::cout << s.singleNumber(a) << std::endl;*/

    return EXIT_SUCCESS;
}
