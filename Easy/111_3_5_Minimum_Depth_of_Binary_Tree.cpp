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
//    int minDepth(TreeNode* root) 
//    {
//        if (root == nullptr)
//            return 0;
//        assert(root != nullptr);
//        if (root->left == nullptr && root->right == nullptr)
//            return 1;
//        if (root->left == nullptr)
//            return minDepth(root->right) + 1;
//        if (root->right == nullptr)
//            return minDepth(root->left) + 1;
//        
//        return std::min(minDepth(root->left), minDepth(root->right));
//    }
//};

// 2 version
//class Solution
//{
//public:
//	int minDepth(TreeNode* root)
//	{
//		if (root == nullptr)
//			return 0;
//
//		std::queue<TreeNode*> curLevel;
//		std::queue<TreeNode*> nextLevel;
//		int level = 1;
//		curLevel.push(root);
//
//		while (true)
//		{
//			while (!curLevel.empty())
//			{
//				TreeNode* node = curLevel.front();
//				curLevel.pop();
//				if (node->left == nullptr && node->right == nullptr)
//					return level;
//				if (node->left != nullptr)
//					nextLevel.push(node->left);
//				if (node->right != nullptr)
//					nextLevel.push(node->right);
//			}
//			curLevel.swap(nextLevel);
//			level++;
//		}
//	}
//};

// 3 version
//class Solution
//{
//public:
//	int minDepth(TreeNode* root)
//	{
//		if (root == nullptr)
//			return 0;
//
//		std::stack<TreeNode*> curLevel;
//		std::stack<TreeNode*> nextLevel;
//		int level = 1;
//		curLevel.push(root);
//
//		while (true)
//		{
//			while (!curLevel.empty())
//			{
//				TreeNode* node = curLevel.top();
//				curLevel.pop();
//				if (node->left == nullptr && node->right == nullptr)
//					return level;
//				if (node->left != nullptr)
//					nextLevel.push(node->left);
//				if (node->right != nullptr)
//					nextLevel.push(node->right);
//			}
//			curLevel.swap(nextLevel);
//			level++;
//		}
//	}
//};

// 4 version
//class Solution
//{
//public:
//	int minDepth(TreeNode* root)
//	{
//		if (root == nullptr)
//			return 0;
//
//		std::stack<TreeNode*, std::vector<TreeNode*>> curLevel;
//		std::stack<TreeNode*, std::vector<TreeNode*>> nextLevel;
//		int level = 1;
//		curLevel.push(root);
//
//		while (true)
//		{
//			while (!curLevel.empty())
//			{
//				TreeNode* node = curLevel.top();
//				curLevel.pop();
//				if (node->left == nullptr && node->right == nullptr)
//					return level;
//				if (node->left != nullptr)
//					nextLevel.push(node->left);
//				if (node->right != nullptr)
//					nextLevel.push(node->right);
//			}
//			curLevel.swap(nextLevel);
//			level++;
//		}
//	}
//};


// 5 version
class Solution
{
public:
	int minDepth(TreeNode* root)
	{
		if (root == nullptr)
			return 0;

		std::vector<TreeNode*> curLevel;
		std::vector<TreeNode*> nextLevel;
		int level = 1;
		curLevel.push_back(root);

		while (true)
		{
			for(TreeNode * node : curLevel)
			{				
				if (node->left == nullptr && node->right == nullptr)
					return level;
				if (node->left != nullptr)
					nextLevel.push_back(node->left);
				if (node->right != nullptr)
					nextLevel.push_back(node->right);
			}
			curLevel.swap(nextLevel);
			nextLevel.clear();
			level++;
		}
	}
};


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
