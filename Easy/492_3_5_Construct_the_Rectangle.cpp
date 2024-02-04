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

// https://www.youtube.com/watch?v=vXBdgvz60oQ
//

// my version

// 1 version
//class Solution 
//{
//public:
//    std::vector<int> constructRectangle(int area) 
//	{
//		int ansW = 0;
//		int ansL = 0;
//		for (int w = 1; w * w <= area; ++w)
//		{
//			if (area % w == 0)
//			{
//				ansW = w;
//				ansL = area / w;
//			}
//		}
//		return { ansL, ansW };
//    }
//};

// 2 version
class Solution
{
public:
	std::vector<int> constructRectangle(int area)
	{
		for (int w = (int)std::sqrt(area); w >= 1; --w)
		{
			if (area % w == 0)
				return { area / w, w };
		}		
		throw std::logic_error("area should be divisible by 1");
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
