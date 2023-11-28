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
//	bool hasCycle(ListNode* head) 
//	{
//		std::unordered_set<ListNode*> visited;
//		while (true)
//		{
//			if (head == nullptr)
//				return false;
//			auto res = visited.insert(head);
//			if (!res.second)
//				return true;
//			head = head->next;
//		}
//	}
//};

// 2 version
//class Solution 
//{
//public:
//	bool hasCycle(ListNode* head) 
//	{
//		ListNode* slow = head;
//		ListNode* fast = head;
//		while (true)
//		{
//			if (fast == nullptr)
//				return false;
//			fast = fast->next;
//			if (fast == nullptr)
//				return false;
//			fast = fast->next;
//			slow = slow->next;
//			if (fast == slow)
//				return true;
//		}
//	}
//};

// 3 version
class Solution 
{
public:
	bool hasCycle(ListNode* head) 
	{
		std::unordered_set<ListNode*> visited;
		while (true)
		{
			if (head == nullptr)
				return false;
			auto [it, inserted] = visited.insert(head);
			if (!inserted)
				return true;
			head = head->next;
		}
	}
};

// 4 version

// 5 version

// 6 version

// 7 version


int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);


	return EXIT_SUCCESS;
}

