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
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// my version

// 1 version
//class Solution 
//{
//public:
//	ListNode* removeElements(ListNode* head, int val) 
//	{
//		while (head != nullptr && head->val == val)
//		{
//			ListNode* t = head;
//			head = head->next;
//			delete t;
//		}
//		if (head == nullptr)
//			return head;
//		ListNode* cur = head;
//		assert(cur->val != val);
//		while (true)
//		{
//			assert(cur != nullptr);
//			assert(cur->val != val);
//			if (cur->next == nullptr)
//				return head;
//			if (cur->next->val == val)
//			{
//				ListNode* t = cur->next;
//				cur->next = cur->next->next;
//				delete t;
//			}
//			else
//				cur = cur->next;
//		}
//	}
//};

// 2 version
class Solution
{
public:
	ListNode* removeElements(ListNode* head, int val)
	{
		while (head != nullptr && head->val == val)
		{			
			head = head->next;			
		}
		if (head == nullptr)
			return head;
		ListNode* cur = head;
		assert(cur->val != val);
		while (true)
		{
			assert(cur != nullptr);
			assert(cur->val != val);
			if (cur->next == nullptr)
				return head;
			if (cur->next->val == val)
			{					
				cur->next = cur->next->next;			
			}
			else
				cur = cur->next;
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

	Solution s;
	//std::cout << s.reverseBits(3) << std::endl;

	int* p1 = (int*)malloc(4 * sizeof(int));
	free(p1);

	return EXIT_SUCCESS;
}
