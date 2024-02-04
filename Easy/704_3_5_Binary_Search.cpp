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

// https:
//

// my version

// 1 version
//class Solution 
//{
//public:
//    int search(const std::vector<int>& a, int target) 
//	{
//		auto it = std::lower_bound(a.begin(), a.end(), target);
//		if (it == a.end())
//			return -1;
//		else if (*it > target)
//			return -1;
//		else
//			return static_cast<int>(it - a.begin());
//    }
//};

// 2 version
//class Solution
//{
//public:
//	int search(const std::vector<int>& a, int target)
//	{
//		int left = 0;
//		int right = (int)a.size() - 1;
//		// answer maybe in [left; right]
//		while (left <= right)
//		{
//			int mid = (left + right) / 2;
//			if (a[mid] < target)
//				left = mid + 1;
//			else if (a[mid] > target)
//				right = mid - 1;
//			else
//				return mid;
//		}
//		return -1;
//	}
//};

// 3 version
class Solution
{
public:
	int search(const std::vector<int>& a, int target)
	{
		int left = -1;
		int right = (int)a.size();
		// a[left] < target, a[right] >= target
		while (left + 1 < right)
		{
			int mid = (left + right) / 2;
			if (a[mid] >= target)
				right = mid;
			else 
				left = mid;			
		}
		if (right == (int)a.size())
			return -1;
		else if (a[right] > target)
			return -1;
		return right;
	}
};

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
