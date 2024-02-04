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

// https://www.youtube.com/watch?v=0IR8YKNfMkQ

// my version

// 1 version
//class Solution 
//{
//public:
//	std::vector<std::string> readBinaryWatch(int num) 
//	{
//		if (num > 10)
//			return {};
//
//		std::vector<int> bits(10, 0);
//		for (int i = (int)bits.size() - 1; i >= (int)bits.size() - num; i--)
//			bits[i] = 1;
//
//		std::vector<std::string> ans;
//		do
//		{
//			int hour = 
//				bits[0] * 8 + 
//				bits[1] * 4 + 
//				bits[2] * 2 + 
//				bits[3] * 1;
//			int minute =
//				bits[4] * 32 +
//				bits[5] * 16 +
//				bits[6] * 8  +
//				bits[7] * 4  +
//				bits[8] * 2  +
//				bits[9] * 1;
//			if (0 <= hour && hour < 12 && 0 <= minute && minute < 60)
//			{
//				char buffer[5 + 1];
//				sprintf(buffer, "%d:%02d", hour, minute);
//				ans.push_back(buffer);
//			}
//		} while (std::next_permutation(bits.begin(), bits.end()));
//
//		return ans;
//	}
//};

// 2 version
class Solution
{
	int countBits(int n)
	{
		int ans = 0;		
		while (n > 0)
		{
			n &= n - 1;
			++ans;
		}
		return ans;
	}

public:
	std::vector<std::string> readBinaryWatch(int num)
	{
		if (num > 10)
			return {};

		std::vector<std::string> ans;

		for (int h = 0; h < 12; ++h)
		{
			for (int m = 0; m < 60; ++m)
			{
				int bits = countBits(h) + countBits(m);
				if (bits == num)
				{
					char buffer[5 + 1];
					sprintf(buffer, "%d:%02d", h, m);
					ans.push_back(buffer);
				}
			}
		}

		return ans;
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
