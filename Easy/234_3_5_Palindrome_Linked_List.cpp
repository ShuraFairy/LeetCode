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
//    int getLen(ListNode* node)
//    {
//        int len = 0;
//        while (node != nullptr)
//        {
//            node = node->next;
//            len++;
//        }
//        return len;
//    }
//
//    ListNode* forward(ListNode * node, int steps)
//    {
//        while (steps > 0)
//        {
//            node = node->next;
//            steps--;
//        }
//        return node;
//    }
//
//    ListNode* reverse(ListNode * head)
//    {
//        ListNode* ans = nullptr;
//        while (head != nullptr)
//        {
//            ListNode* node = head;
//            head = head->next;
//            node->next = ans;
//            ans = node;
//        }
//        return ans;
//    }
//
//public:
//    bool isPalindrome(ListNode* head) 
//    {
//        int len = getLen(head);
//        ListNode* half2 = forward(head, (len + 1) / 2);
//        ListNode* last = reverse(half2);
//        ListNode* node1 = head;
//        ListNode* node2 = last;
//        while (node2 != nullptr)
//        {
//            if (node1->val != node2->val)
//            {
//                reverse(last);
//                return false;
//            }
//            node1 = node1->next;
//            node2 = node2->next;
//        }
//        reverse(last);
//        return ;
//    }
//};

// 2 version
class Solution
{
    int getLen(ListNode* node)
    {
        int len = 0;
        while (node != nullptr)
        {
            node = node->next;
            len++;
        }
        return len;
    }

    ListNode* forward(ListNode* node, int steps)
    {
        while (steps > 0)
        {
            node = node->next;
            steps--;
        }
        return node;
    }

    ListNode* reverse(ListNode* head)
    {
        ListNode* ans = nullptr;
        while (head != nullptr)
        {
            ListNode* node = head;
            head = head->next;
            node->next = ans;
            ans = node;
        }
        return ans;
    }

public:
    bool isPalindrome(ListNode* head)
    {
        int len = getLen(head);
        ListNode* half2 = forward(head, (len + 1) / 2);
        ListNode* last = reverse(half2);
        ListNode* node1 = head;
        ListNode* node2 = last;
        while (node2 != nullptr)
        {
            if (node1->val != node2->val)
            {                
                return false;
            }
            node1 = node1->next;
            node2 = node2->next;
        }
        
        return true;
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

//    Solution s;
    
    std::vector<int> a{ 0, 0, 2, 1 };
    std::vector<int> ans;
//    std::cout << s.isPowerOfTwo(1) << std::endl;

    return EXIT_SUCCESS;
}
