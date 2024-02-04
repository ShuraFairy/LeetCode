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
//    int findLHS(std::vector<int>& nums) 
//	{
//		std::unordered_map<int, int> numCount;
//		for (int v : nums)
//			numCount[v]++;
//		int ans = 0;
//		for (const auto& kv : numCount)
//		{
//			int min = kv.first;
//			if (min < INT_MAX)
//			{
//				int max = min + 1;
//				auto it = numCount.find(max);
//				if (it != numCount.end())
//					ans = std::max(ans, kv.second + it->second);
//			}
//		}
//		return ans;
//    }
//};

// 2 version
class Solution 
{
public:
	int findLHS(std::vector<int>& nums) 
	{
		std::sort(nums.begin(), nums.end());
		int ans = 0;
		int prevGroupSize = 0;
		int prevGroupValue = 0;
		int curGroupSize = 0;
		int curGroupValue = 0;
		for (int v : nums)
		{
			if (v == curGroupValue)
			{
				curGroupSize++;
			}
			else
			{
				prevGroupSize = curGroupSize;
				prevGroupValue = curGroupValue;
				curGroupSize = 1;
				curGroupValue = v;
			}	
			if (prevGroupSize > 0 && prevGroupValue + 1 == curGroupValue)
				ans = std::max(ans, prevGroupSize + curGroupSize);
		}
		return ans;
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
