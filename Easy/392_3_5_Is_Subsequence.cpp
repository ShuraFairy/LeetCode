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

// https://www.youtube.com/watch?v=J8ii90nFNKQ
// ֶאהםûי אכדמנטעל

// my version

// 1 version
//class Solution 
//{
//public:
//    bool isSubsequence(const std::string & sub, const std::string & s) 
//	{
//		if (sub.empty())
//			return true;
//		int i = 0;
//		for (char c : s)
//		{
//			if (c == sub[i])
//			{
//				++i;
//				if (i == (int)sub.size())
//					return true;
//			}
//		}
//		return false;
//    }
//};

// 2 version
//class Solution
//{
//public:
//	bool isSubsequence(const std::string& sub, const std::string& s)
//	{
//		if (sub.empty())
//			return true;
//
//		const int NOT_FOUND = -1;
//		std::vector<std::vector<int>> next(s.size() + 1, std::vector<int>('z' - 'a' + 1, NOT_FOUND));
//		for (int i = (int)s.size() - 1; i >= 0; i--)
//		{
//			next[i] = next[i + 1];
//			next[i][s[i] - 'a'] = i;
//		}
//		int subPos = 0;
//		int sPos = 0;
//		while (true)
//		{
//			sPos = next[sPos][sub[subPos] - 'a'];
//			if (sPos == NOT_FOUND)
//				return false;
//			++subPos;
//			if (subPos == (int)sub.size())
//				return true;
//			++sPos;
//		}
//	}
//};

// 3 version
class Solution
{
	const char* prevS = nullptr;
	int prevSsize = -1;
	std::vector<std::vector<int>> next;

public:
	bool isSubsequence(const std::string& sub, const std::string& s)
	{
		if (sub.empty())
			return true;

		const int NOT_FOUND = -1;
		if (prevS == &s[0] && prevSsize == (int)s.size())
		{
			// nothing to do
		}
		else
		{
			next = std::vector<std::vector<int>>(s.size() + 1, std::vector<int>('z' - 'a' + 1, NOT_FOUND));
			prevS = &s[0];
			prevSsize = (int)s.size();
			for (int i = (int)s.size() - 1; i >= 0; i--)
			{
				next[i] = next[i + 1];
				next[i][s[i] - 'a'] = i;
			}
		}
		int subPos = 0;
		int sPos = 0;
		while (true)
		{
			sPos = next[sPos][sub[subPos] - 'a'];
			if (sPos == NOT_FOUND)
				return false;
			++subPos;
			if (subPos == (int)sub.size())
				return true;
			++sPos;
		}
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
