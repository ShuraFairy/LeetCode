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

// https://www.youtube.com/watch?v=YWwLlekcOTc

// my version

// 1 version
//class Solution 
//{
//public:
//    int hammingWeight(uint32_t n) 
//	{
//		int ans = 0;
//		while (n > 0)
//		{
//			ans += n % 2;
//			n /= 2;
//		}
//		return ans;
//    }
//};

// 2 version
//class Solution
//{
//public:
//	int hammingWeight(uint32_t n)
//	{
//		int ans = 0;
//		while (n > 0)
//		{
//			n = n & (n - 1);
//			++ans;
//		}
//		return ans;
//	}
//};

// 3 version
//class Solution
//{
//public:
//	int hammingWeight(uint32_t n)
//	{	
//		return std::bitset<32>(n).count();
//	}
//};

// 4 version
//class Solution
//{
//public:
//	int hammingWeight(uint32_t n)
//	{
//		return __builtin_popcount(n);
//	}
//};

// 5 version
//class Solution
//{
//public:
//	int hammingWeight(uint32_t n)
//	{
//		n = ((n >> 1) & 0x55555555) + (n & 0x55555555);
//		n = ((n >> 2) & 0x33333333) + (n & 0x33333333);
//		n = ((n >> 4) & 0x0F0F0F0F) + (n & 0x0F0F0F0F);
//		n = ((n >> 8) & 0x00FF00FF) + (n & 0x00FF00FF);
//		n = ((n >> 16) & 0x0000FFFF) + (n & 0x0000FFFF);
//		return n;
//	}
//};

// 6 version
//class Solution
//{
//public:
//	int hammingWeight(uint32_t n)
//	{		
//		n = n - ((n >> 1) & 0x55555555);
//		n = ((n >> 2) & 0x33333333) + (n & 0x33333333);
//		n = ((n >> 4) & 0x0F0F0F0F) + (n & 0x0F0F0F0F);
//		return (n * 0x01010101) >> 24;
//	}
//};

// 7 version
//class Solution
//{
//	char count[1 << 16];
//public:
//
//	Solution()
//	{
//		count[0] = 0;
//		for (int i = 1; i < sizeof(count) / sizeof(char); ++i)
//		{			
//			count[i] = char(count[i >> 1] + (i & 1));
//		}
//	}
//
//	int hammingWeight(uint32_t n)
//	{
//		return count[n >> 16] + count[n << 16 >> 16];
//	}
//};

//// 8 version
//class Solution
//{
//	char count[1 << 11];
//public:
//
//	Solution()
//	{
//		count[0] = 0;
//		for (int i = 1; i < sizeof(count) / sizeof(char); ++i)
//		{
//			count[i] = char(count[i >> 1] + (i & 1));
//		}
//	}
//
//	int hammingWeight(uint32_t n)
//	{
//		return count[n >> 22] + count[n >> 11 << 21 >> 21] + count[n << 21 >> 21];
//	}
//};

// 9 version
class Solution
{
	char count[1 << 11];
public:

	Solution()
	{
		count[0] = 0;
		for (int i = 1; i < sizeof(count) / sizeof(char); ++i)
		{
			count[i] = char(count[i >> 1] + (i & 1));
		}
	}

	int hammingWeight(uint32_t n)
	{
		return count[n >> 22] + 
			   count[(n >> 11) & 0b111'1111'1111] + 
			   count[n & 0b111'1111'1111];
	}
};


int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);


	return EXIT_SUCCESS;
}
