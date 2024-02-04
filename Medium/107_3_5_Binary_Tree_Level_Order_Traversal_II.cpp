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

// https://
//

// my version

// 1 version
class Solution 
{
	void visit(TreeNode* node, int level, std::vector<std::vector<int>> & ans)
	{
		if (node == nullptr)
			return;
		if (level >= (int)ans.size())
			ans.push_back(std::vector<int>());
		assert(level < (int)ans.size());
		visit(node->left, level + 1, ans);
		ans[level].push_back(node->val);
		visit(node->right, level + 1, ans);
	}

public:
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) 
	{
		std::vector<std::vector<int>> ans;
		visit(root, 0, ans);
		std::reverse(ans.begin(), ans.end());
		return ans;
    }
};

// 2 version

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
