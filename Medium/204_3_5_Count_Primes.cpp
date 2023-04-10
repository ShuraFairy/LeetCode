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
// !!! Time Limit Exceeded
//class Solution
//{
//    bool isPrime(int n)
//    {
//        if (n <= 1)
//            return false;
//        for (int i = 2; i < n; ++i)
//            if (n % i == 0)
//                return false;
//
//        return true;
//    }
//
//public:
//    int countPrimes(int n)
//    {
//        int count = 0;
//        for (int i = 2; i < n; ++i)
//            if (isPrime(i))
//                ++count;
//        return count;
//    }
//};

// my version 2
// !!! Time Limit Exceeded
//class Solution 
//{
//    bool isPrime(int n)
//    {
//        if (n <= 1)
//            return false;
//        if (n <= 3)
//            return true;
//        if (n % 2 == 0 || n % 3 == 0)
//            return false;
//
//        for (int i = 5; i * i < n; i = i + 6)
//            if (n % i == 0 || n % (i + 2) == 0)
//                return false;
//
//        return true;
//    }
//
//public:
//    int countPrimes(int n) 
//    {
//        int count = 0;
//        for (int i = 2; i < n; ++i)
//            if (isPrime(i))
//                ++count;
//        return count;
//    }
//};

// 1 version
class Solution 
{
public:
    int countPrimes(int n) 
    {
        if (n <= 2)
            return 0;
        std::vector<bool> isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int p = 2; p * p < n; ++p)
        {
            if (isPrime[p])
            {
                for (int i = p * p; i < n; i += p)
                    isPrime[i] = false;
            }
        }
        int count = 0;
        for (int i = 2; i < n; ++i)
        {
            if (isPrime[i])
                ++count;
        }
        return count;
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
    //std::cout << s.reverseBits(3) << std::endl;
    
    int* p1 = (int*)malloc(4 * sizeof(int));
    free(p1);    

    return EXIT_SUCCESS;
}
