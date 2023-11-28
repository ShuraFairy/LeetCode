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
//    std::vector<int> findErrorNums(const std::vector<int>& a) 
//	{
//		long long sum = 0;
//		long long sum2 = 0;
//		long long needSum = 0;
//		long long needSum2 = 0;
//		for (int i = 0; i < (int)a.size(); ++i)
//		{
//			sum += a[i];
//			sum2 += a[i] * a[i];
//			needSum += (i + 1);
//			needSum2 += (i + 1) * (i + 1);
//		}
//		// new - old = sum - needSum
//		// nem^2 - old^2 = sum2 - needSum2
//
//		// new + old = (sum2 - needSum2) / (sum - needSum)
//		// new - old = sum - needSum
//
//		// new = ((sum2 - needSum2) / (sum - needSum) + (sum - needSum)) / 2
//		// old = ((sum2 - needSum2) / (sum - needSum) - (sum - needSum)) / 2
//
//		return
//		{
//			int((sum2 - needSum2) / (sum - needSum) + (sum - needSum)) / 2,
//			int((sum2 - needSum2) / (sum - needSum) - (sum - needSum)) / 2
//		};
//    }
//};

// 2 version
class Solution 
{
public:
	std::vector<int> findErrorNums(std::vector<int>& a) 
	{
		for (int i = 0; i < static_cast<int>(a.size()); ++i)
		{
			while (true)
			{
				int j = a[i] - 1;
				if (a[j] == a[i])
					break;
				std::swap(a[i], a[j]);
			}
		}
		
		for (int i = 0; i < static_cast<int>(a.size()); ++i)
		{
			if (a[i] != i + 1)
				return { a[i], i + 1 };
		}
		throw std::invalid_argument("1..n array without change");
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
