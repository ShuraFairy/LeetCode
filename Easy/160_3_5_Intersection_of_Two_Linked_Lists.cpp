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

// 1 version
//class Solution 
//{
//public:
//    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) 
//    {
//        ListNode* a = headA;
//        ListNode* b = headB;
//        if ((a == nullptr) != (b == nullptr))
//            return nullptr;
//        while (true)
//        {
//            if (a == b)
//                return a;
//            a = a->next;
//            b = b->next;
//            if (a == b)
//                return a;
//            if (a == nullptr)
//                a = headB;
//            if (b == nullptr)
//                b = headA;        
//        }
//    }
//};

// 2 version
class Solution
{
    int getLen(ListNode* a)
    {
        int len = 0;
        while (a != nullptr)
        {
            len++;
            a = a->next;
        }
        return len;
    }

    ListNode* shift(ListNode* a, int steps)
    {
        assert(steps >= 0);
        while (steps > 0)
        {
            a = a->next;
            steps--;
        }
        return a;
    }

public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        int lenA = getLen(headA);
        int lenB = getLen(headB);
        ListNode* a = shift(headA, std::max(0, lenA - lenB));
        ListNode* b = shift(headB, std::max(0, lenB - lenA));
        while (true)
        {
            if (a == b)
                return a;
            a = a->next;
            b = b->next;
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
    //std::cout << s.reverseBits(3) << std::endl;
    
    int* p1 = (int*)malloc(4 * sizeof(int));
    free(p1);    

    return EXIT_SUCCESS;
}
