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
#include <algorithm>
#include <numeric>
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
//	bool areTreeEqual(TreeNode* n1, TreeNode* n2)
//	{
//		if (n1 == nullptr && n2 == nullptr)
//			return true;
//		else if (n1 == nullptr || n2 == nullptr)
//			return false;
//		else
//			return n1->val == n2->val &&
//			areTreeEqual(n1->left, n2->left) &&
//			areTreeEqual(n1->right, n2->right);
//	}
//
//public:
//	bool isSubtree(TreeNode* s, TreeNode* t)
//	{
//		if (s == nullptr)
//			return false;
//		else
//			return areTreeEqual(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
//	}
//};

// 2 version
//class Solution
//{
//	int getHeight(TreeNode* n)
//	{
//		if (n == nullptr)
//			return 0;
//		else
//			return (1 + std::max(getHeight(n->left), getHeight(n->right)));
//	}
//
//	bool areTreesEqual(TreeNode* n1, TreeNode* n2)
//	{
//		if (n1 == nullptr && n2 == nullptr)
//			return true;
//		else if (n1 == nullptr || n2 == nullptr)
//			return false;
//		else
//			return n1->val == n2->val &&
//			areTreesEqual(n1->left, n2->left) &&
//			areTreesEqual(n1->right, n2->right);
//	}
//
//	// returns: >= 0 -> height(s), < 0 -> match
//	int visit(TreeNode* s, TreeNode* t, int tHeight)
//	{
//		if (s == nullptr)
//			return 0;
//		int leftHeight = visit(s->left, t, tHeight);
//		if (leftHeight < 0)
//			return -1;
//		int rightHeight = visit(s->right, t, tHeight);
//		if (rightHeight < 0)
//			return -1;
//		int sHeight = 1 + std::max(leftHeight, rightHeight);
//		if (sHeight == tHeight)
//		{
//			if (areTreesEqual(s, t))
//				return -1;
//		}
//		return sHeight;
//	}
//
//public:
//	bool isSubtree(TreeNode* s, TreeNode* t)
//	{
//		int tHeight = getHeight(t);
//		return visit(s, t, tHeight) < 0;
//	}
//};

// 3 version
class Solution
{
	bool areTreeEqual(TreeNode* n1, TreeNode* n2)
	{
		if (n1 == nullptr && n2 == nullptr)
			return true;
		else if (n1 == nullptr || n2 == nullptr)
			return false;
		else
			return n1->val == n2->val &
			areTreeEqual(n1->left, n2->left) &
			areTreeEqual(n1->right, n2->right);
	}

public:
	bool isSubtree(TreeNode* s, TreeNode* t)
	{
		if (s == nullptr)
			return false;
		else
			return areTreeEqual(s, t) | isSubtree(s->left, t) | isSubtree(s->right, t);
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
