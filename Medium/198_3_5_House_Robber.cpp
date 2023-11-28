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
//public:
//    int rob(std::vector<int>& a) 
//	{
//		if (a.empty())
//			return 0;
//		std::vector<int>& maxSum = a;
//		if(1 < a.size())
//			maxSum[1] = std::max(maxSum[0], a[1]);
//		for (size_t i = 2; i < a.size(); ++i)
//		{
//			maxSum[i] = std::max(a[i] + maxSum[i - 2], maxSum[i - 1]);
//		}
//		return maxSum.back();
//    }
//};

// 2 version
class Solution
{
public:
	int rob(const std::vector<int>& a)
	{
		if (a.empty())
			return 0;
		if (a.size() == 1)
			return a[0];
		int prevMaxSum = a[0];
		int curMaxSum = std::max(a[0], a[1]);
		for (size_t i = 2; i < a.size(); ++i)
		{
			int nextMaxSum = std::max(a[i] + prevMaxSum, curMaxSum);
			prevMaxSum = curMaxSum;
			curMaxSum = nextMaxSum;
		}

		return curMaxSum;
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


	return EXIT_SUCCESS;
}
