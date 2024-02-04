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

// https://www.youtube.com/watch?v=e3tovJY8AiI

// my version

// 1 version
//class Solution 
//{
//	bool pairExists(TreeNode* node, int sum, std::unordered_set<int> & values)
//	{
//		if (node == nullptr)
//			return false;
//		if (pairExists(node->left, sum, values))
//			return true;
//		if (values.count(sum - node->val))
//			return true;
//		values.insert(node->val);
//		return pairExists(node->right, sum, values);
//	}
//
//public:
//    bool findTarget(TreeNode* root, int sum) 
//	{
//		std::unordered_set<int> values;
//		return pairExists(root, sum, values);
//    }
//};

// 2 version
class Solution
{
	struct UpIterator
	{
		std::stack<TreeNode*, std::vector<TreeNode*>> path;
		UpIterator(TreeNode* root)
		{
			TreeNode* node = root;
			while (node != nullptr)
			{
				path.push(node);
				node = node->left;
			}
		}
		TreeNode* get() const
		{
			if (path.empty())
				return nullptr;
			else
				return path.top();
		}
		void next()
		{
			assert(!path.empty());
			if (path.top()->right != nullptr)
			{
				TreeNode* node = path.top()->right;
				path.pop();
				while (node != nullptr)
				{
					path.push(node);
					node = node->left;
				}
			}
			else
				path.pop();
		}
	};

	struct DownIterator
	{
		std::stack<TreeNode*, std::vector<TreeNode*>> path;
		DownIterator(TreeNode* root)
		{
			TreeNode* node = root;
			while (node != nullptr)
			{
				path.push(node);
				node = node->right;
			}
		}
		TreeNode* get() const
		{
			if (path.empty())
				return nullptr;
			else
				return path.top();
		}
		void next()
		{
			assert(!path.empty());
			if (path.top()->left != nullptr)
			{
				TreeNode* node = path.top()->left;
				path.pop();
				while (node != nullptr)
				{
					path.push(node);
					node = node->right;
				}
			}
			else
				path.pop();
		}
	};

public:
	bool findTarget(TreeNode* root, int sum)
	{
		auto i = UpIterator(root);
		auto j = DownIterator(root);
		while (true)
		{
			TreeNode* ip = i.get();
			TreeNode* jp = j.get();
			if (ip == jp)
				return false;
			if (ip == nullptr && jp == nullptr)
				return false;
			int iv = ip->val;
			int jv = jp->val;
			
			if (iv + jv < sum)
				i.next();
			else if (iv + jv > sum)
				j.next();
			else
				true;
		}
  
        throw std::logic_error("got after the loop");
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
