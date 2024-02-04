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

//#pragma GCC target("popcnt")

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

// https://www.youtube.com/watch?v=Q2TSiZzRJzM
//

// my version

// 1 version
//class Solution 
//{
//public:
//	int sumOfLeftLeaves(TreeNode* root) 
//	{
//		if (root == nullptr)
//			return 0;
//		int sum = 0;
//		if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
//			sum = root->left->val;
//		else
//			sum = sumOfLeftLeaves(root->left);
//
//		return sum + sumOfLeftLeaves(root->right);
//	}
//};


// 2 version
class Solution
{
	int sumOfLeftLeaves(TreeNode* node, bool isLeft)
	{
		if (node == nullptr)
			return 0;
		if (node->left == nullptr && node->right == nullptr)
		{
			if (isLeft)
				return node->val;
			else
				return 0;
		}
		return sumOfLeftLeaves(node->left, true) + sumOfLeftLeaves(node->right, false);		
	}

public:
	int sumOfLeftLeaves(TreeNode* root)
	{
		return sumOfLeftLeaves(root, false);		
	}
};

// 3 version

// 4 version

// 5 version

// 6 version

// 7 version

// 8 version

// 9 version


int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);


	return EXIT_SUCCESS;
}
