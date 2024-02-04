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

// https://www.youtube.com/watch?v=VE8K6yFSv_s
// Динамический программирование

// my version

// 1 version
//class Solution 
//{
//public:
//    int minCostClimbingStairs(const std::vector<int>& cost) 
//	{
//		std::vector<int> minCost(cost.size());
//		minCost[0] = cost[0];
//		minCost[1] = cost[1];
//		for (int i = 2; i < (int)cost.size(); ++i)
//		{
//			minCost[i] = cost[i] + std::min(minCost[i - 1], minCost[i - 2]);
//		}
//		return std::min(minCost.back(), minCost[minCost.size() - 2]);
//    }
//};

// 2 version
class Solution
{
public:
	int minCostClimbingStairs(const std::vector<int>& cost)
	{
		int prev = cost[0];
		int curr = cost[1];
		
		for (int i = 2; i < (int)cost.size(); ++i)
		{
			int next = cost[i] + std::min(prev, curr);
			prev = curr;
			curr = next;
		}
		return std::min(prev, curr);
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
