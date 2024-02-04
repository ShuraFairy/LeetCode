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

// https://www.youtube.com/watch?v=ZBu9Y7-NwvI
// 

// my version

// 1 version
//class Solution 
//{
//public:
//    std::string tree2str(TreeNode* t) 
//	{
//		if (t == nullptr)
//			return "";
//		else
//		{
//			assert(t != nullptr);
//			if (t->left == nullptr)
//			{
//				if(t->right == nullptr)
//					return std::to_string(t->val);
//				else
//					return std::to_string(t->val) + "()(" + tree2str(t->right) + ")";
//			}
//			else
//			{
//				assert(t->left != nullptr);
//				if(t->right == nullptr)
//					return std::to_string(t->val) + "(" + tree2str(t->left) + ")";
//				else
//				{
//					assert(t->right != nullptr);
//					return std::to_string(t->val) + "(" + tree2str(t->left) + ")(" + tree2str(t->right) + ")";
//				}
//			}
//		}	
//    }
//};

// 2 version
//class Solution
//{
//public:
//	std::string tree2str(TreeNode* t)
//	{
//		if (t == nullptr)
//			return "";
//
//		std::string ans = std::to_string(t->val);
//		if(t->left != nullptr || t->right != nullptr)
//			ans += "(" + tree2str(t->left) + ")";
//		if(t->right != nullptr)
//			ans += "(" + tree2str(t->right) + ")";
//		return ans;
//	}
//};

// 3 version
//class Solution
//{
//public:
//	std::string tree2str(TreeNode* t)
//	{
//		if (t == nullptr)
//			return "";
//
//		std::string ans = std::to_string(t->val);
//		if (t->left != nullptr || t->right != nullptr)
//		{
//			if (t->left == nullptr)
//				ans += "()";
//			else
//				ans += "(" + tree2str(t->left) + ")";
//		}
//		if (t->right != nullptr)
//			ans += "(" + tree2str(t->right) + ")";
//		return ans;
//	}
//};

// 4 version
//class Solution
//{
//	void visit(TreeNode* t, std::vector<char>& ans)
//	{
//		if (t == nullptr)
//			return;
//		for (char c : std::to_string(t->val))
//			ans.push_back(c);
//		if (t->left != nullptr || t->right != nullptr)
//		{
//			ans.push_back('(');
//			visit(t->left, ans);
//			ans.push_back(')');
//		}
//		if (t->right != nullptr)
//		{
//			ans.push_back('(');
//			visit(t->right, ans);
//			ans.push_back(')');
//		}
//	}
//
//public:
//	std::string tree2str(TreeNode* t)
//	{
//		std::vector<char> ans;
//		visit(t, ans);
//		return std::string(ans.begin(), ans.end());
//	}
//};

// 5 version
//class Solution
//{
//	void visit(TreeNode* t, std::vector<char>& ans)
//	{
//		if (t == nullptr)
//			return;
//		for (char c : std::to_string(t->val))
//			ans.push_back(c);
//		if (t->left != nullptr || t->right != nullptr)
//		{
//			ans.push_back('(');
//			if(t->left != nullptr)
//				visit(t->left, ans);
//			ans.push_back(')');
//		}
//		if (t->right != nullptr)
//		{
//			ans.push_back('(');
//			visit(t->right, ans);
//			ans.push_back(')');
//		}
//	}
//
//public:
//	std::string tree2str(TreeNode* t)
//	{
//		std::vector<char> ans;
//		visit(t, ans);
//		return std::string(ans.begin(), ans.end());
//	}
//};


// 6 version
//class Solution
//{
//	struct Item
//	{
//		TreeNode* node;	// node != nullptr -> use str
//		std::string str;
//	};
//
//public:
//	std::string tree2str(TreeNode* t)
//	{
//		std::list<Item> list;
//		list.push_back(Item{ t, "" });
//		auto it = list.begin();
//		while (it != list.end())
//		{			
//			if (it->node != nullptr)
//			{
//				auto it0 = it;
//				TreeNode* node = it->node;
//				it->node = nullptr;
//				it->str = std::to_string(node->val);
//				if (node->left != nullptr || node->right != nullptr)
//				{
//					++it;
//					it = list.insert(it, Item{ nullptr, "(" });
//					++it;
//					it = list.insert(it, Item{ node->left, "" });
//					++it;
//					it = list.insert(it, Item{ nullptr, ")" });
//				}
//				if (node->right != nullptr)
//				{
//					++it;
//					it = list.insert(it, Item{ nullptr, "(" });
//					++it;
//					it = list.insert(it, Item{ node->right, "" });
//					++it;
//					it = list.insert(it, Item{ nullptr, ")" });
//				}
//				it = it0;
//			}
//			++it;
//		}
//		std::vector<char> v;
//		for (const Item& item : list)
//		{
//			for (char c : item.str)
//				v.push_back(c);
//		}
//
//		return std::string(v.begin(), v.end());
//	}
//};

// 7 version
class Solution
{
	struct Item
	{
		TreeNode* node;	// node != nullptr -> use str
		std::string str;
	};

public:
	std::string tree2str(TreeNode* t)
	{
		std::vector<char> v;
		std::stack<Item, std::vector<Item>> stack;
		stack.push(Item{ t, "" });

		while (!stack.empty())
		{
			if (stack.top().node != nullptr)
			{
				TreeNode* node = stack.top().node;
				stack.pop();
				for (char c : std::to_string(node->val))
					v.push_back(c);

				if (node->right != nullptr)
				{
					stack.push(Item{ nullptr, ")" });
					stack.push(Item{ node->right, "" });
					stack.push(Item{ nullptr, "(" });
				}
				if (node->left != nullptr || node->right != nullptr)
				{
					stack.push(Item{ nullptr, ")" });
					stack.push(Item{ node->left, "" });
					stack.push(Item{ nullptr, "(" });
				}
			}
			else
			{
				for (char c : stack.top().str)
					v.push_back(c);
				stack.pop();
			}
		}
	
		return std::string(v.begin(), v.end());
	}
};


// 8 version

// 9 version


int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);


	return EXIT_SUCCESS;
}
