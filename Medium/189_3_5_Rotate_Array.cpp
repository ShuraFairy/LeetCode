#include <cstdio>   
#include <cstdlib> 
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

// Definition for singly - linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}    
};

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
//    void rotate(std::vector<int>& a, int k)
//    {
//        if (a.size() <= k)
//            std::rotate(a.rbegin(), a.rbegin() + k % a.size(), a.rend());
//        else
//            std::rotate(a.rbegin(), a.rbegin() + k, a.rend());
//    }
//};

// 1 version
// Time Limit Exceeded
//class Solution 
//{
//public:
//    void rotate(std::vector<int>& a, int k) 
//    {
//        k %= a.size();
//        while (k > 0)
//        {
//            int last = a.back();
//            for (int i = (int)a.size() - 2; i >= 0; i--)
//            {
//                a[i + 1] = a[i];
//            }
//            a[0] = last;
//            k--;
//        }
//    }
//};

// 2 version
//class Solution
//{
//public:
//    void rotate(std::vector<int>& a, int k)
//    {
//        std::vector<int> b = a;
//        int n = (int)a.size();
//        for (int i = 0; i < n; i++)
//        {
//            a[(i + k) % n] = b[i];
//        }
//    }
//};
 
// 3 version
//class Solution
//{
//    int gcd(int a, int b)
//    {
//        while (b > 0)
//        {
//            int t = a % b;
//            a = b;
//            b = t;
//        }
//        return a;
//    }
//
//public:
//    void rotate(std::vector<int>& a, int k)
//    {        
//        int n = (int)a.size();
//        int g = gcd(n, k);
//        for (int start = 0; start < g; ++start)
//        {
//            int i = start;
//            int v = a[i];
//            while (true)
//            {
//                int next = (i + k) % n;
//                if (next == start)
//                {
//                    a[next] = v;
//                    break;
//                }
//                int nextV = a[next];
//                a[next] = v;
//                v = nextV;
//                i = next;
//            }
//        }
//    }
//};

// 4 version
//class Solution
//{
//    void reverse(std::vector<int>& a, int first, int after)
//    {
//        while (true)
//        {
//            if (first == after)
//                break;
//            after--;
//            if (first == after)
//                break;
//            std::swap(a[first], a[after]);
//            first++;
//        }
//    }
//
//public:
//    void rotate(std::vector<int>& a, int k)
//    {
//        int n = (int)a.size();
//        k %= n;
//        if (k == 0)
//            return;
//        reverse(a, 0, n);
//        reverse(a, 0, k);
//        reverse(a, k, n);
//    }
//};

// 5 version
//class Solution
//{
//    
//public:
//    void rotate(std::vector<int>& a, int k)
//    {
//        int n = (int)a.size();
//        k %= n;
//        if (k == 0)
//            return;
//        std::reverse(a.begin(), a.end());
//        std::reverse(a.begin(), a.begin() + k);
//        std::reverse(a.begin() + k, a.end());
//    }
//};

// 6 version
class Solution
{

public:
    void rotate(std::vector<int>& a, int k)
    {
        int n = (int)a.size();
        k %= n;
        if (k == 0)
            return;
        std::rotate(a.begin(), a.begin() + (n - k), a.end());        
    }
};

// 7 version

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    std::ios_base::sync_with_stdio(false);    
    std::cin.tie(nullptr);        

//    Solution s;
    //std::cout << s.reverseBits(3) << std::endl;
    
    int* p1 = (int*)malloc(4 * sizeof(int));
    free(p1);    

    return EXIT_SUCCESS;
}
