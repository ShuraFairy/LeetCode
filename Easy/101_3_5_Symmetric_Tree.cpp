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
//	bool isSymmetric(TreeNode* left, TreeNode* right)
//	{
//		if (left == nullptr && right == nullptr)
//			return true;
//		if (left == nullptr || right == nullptr)
//			return false;
//
//		return left->val == right->val &&
//			isSymmetric(left->left, right->right) &&
//			isSymmetric(left->right, right->left);
//	}
//
//public:
//	bool isSymmetric(TreeNode* root) 
//	{
//		if (root == nullptr)
//			return true;
//
//		return isSymmetric(root->left, root->right);
//	}
//};

// 2 version
//class Solution
//{
//
//public:
//	bool isSymmetric(TreeNode* root)
//	{
//		if (root == nullptr)
//			return true;
//
//		std::stack<std::pair<TreeNode*, TreeNode*>, std::vector<std::pair<TreeNode*, TreeNode*>>> st;
//		st.push({ root->left, root->right });
//		while (!st.empty())
//		{
//			TreeNode* left;
//			TreeNode* right;
//			std::tie(left, right) = st.top();
//			st.pop();
//			if (left == nullptr && right == nullptr)
//				continue;
//			if (left == nullptr || right == nullptr)
//				return false;
//			if (left->val != right->val)
//				return false;
//			st.push({ left->left, right->right });
//			st.push({ left->right, right->left });
//		}
//
//		return true;
//	}
//};

// 3 version
//class Solution
//{
//
//public:
//	bool isSymmetric(TreeNode* root)
//	{
//		if (root == nullptr)
//			return true;
//
//		std::stack<std::pair<TreeNode*, TreeNode*>, std::vector<std::pair<TreeNode*, TreeNode*>>> st;
//		if (root->left == nullptr && root->right == nullptr)
//		{
//			// nothing to do
//		}
//		else if (root->left == nullptr || root->right == nullptr)
//			return false;
//		else if (root->left->val != root->right->val)
//			return false;
//		else
//			st.push({ root->left, root->right });
//
//		while (!st.empty())
//		{
//			TreeNode* left;
//			TreeNode* right;
//			std::tie(left, right) = st.top();
//			st.pop();	
//			if (left->left == nullptr && right->right == nullptr)
//			{
//				// nothing to do
//			}
//			else if (left->left == nullptr || right->right == nullptr)
//				return false;
//			else if (left->left->val != right->right->val)
//				return false;
//			else
//			{
//				st.push({ left->left, right->right });
//			}
//
//			if (left->right == nullptr && right->left == nullptr)
//			{
//				// nothing to do
//			}
//			else if (left->right == nullptr || right->left == nullptr)
//				return false;
//			else if (left->right->val != right->left->val)
//				return false;
//			else
//			{
//				st.push({ left->right, right->left });
//			}
//		}
//
//		return true;
//	}
//};

// 4 version
class Solution
{

public:
	bool isSymmetric(TreeNode* root)
	{
		if (root == nullptr)
			return true;

		std::stack<std::pair<TreeNode*, TreeNode*>> st;
		if (root->left == nullptr && root->right == nullptr)
		{
			// nothing to do
		}
		else if (root->left == nullptr || root->right == nullptr)
			return false;
		else if (root->left->val != root->right->val)
			return false;
		else
			st.push({ root->left, root->right });

		while (!st.empty())
		{
			TreeNode* left;
			TreeNode* right;
			std::tie(left, right) = st.top();
			st.pop();
			if (left->left == nullptr && right->right == nullptr)
			{
				// nothing to do
			}
			else if (left->left == nullptr || right->right == nullptr)
				return false;
			else if (left->left->val != right->right->val)
				return false;
			else
			{
				st.push({ left->left, right->right });
			}

			if (left->right == nullptr && right->left == nullptr)
			{
				// nothing to do
			}
			else if (left->right == nullptr || right->left == nullptr)
				return false;
			else if (left->right->val != right->left->val)
				return false;
			else
			{
				st.push({ left->right, right->left });
			}
		}

		return true;
	}
};

// 5 version

// 6 version

// 7 version


int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);


	return EXIT_SUCCESS;
}
