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
//	bool repeatedSubstringPattern(const std::string & s) 
//	{
//		for (int period = 1; 2 * period <= (int)s.size(); ++period)
//		{
//			if ((int)s.size() % period == 0)
//			{
//				bool good = true;
//				for (int i = period; i < (int)s.size(); ++i)
//				{
//					if (s[i] != s[i - period])
//					{
//						good = false;
//						break;
//					}
//				}
//				if (good)
//					return true;
//			}
//		}
//		return false;
//	}
//};

// 2 version
//class Solution 
//{
//public:
//	bool repeatedSubstringPattern(const std::string & s) 
//	{
//		for (int period = 1; 2 * period <= (int)s.size(); ++period)
//		{
//			if ((int)s.size() % period == 0)
//			{
//				bool good = true;
//				for (int i = (int)s.size() - 1; i >= period; --i)
//				{
//					if (s[i] != s[i - period])
//					{
//						good = false;
//						break;
//					}
//				}
//				if (good)
//					return true;
//			}
//		}
//		return false;
//	}
//};

// 3 version
//class Solution
//{
//public:
//	bool repeatedSubstringPattern(const std::string& s)
//	{
//		return (s + s).find(s, 1) < s.size();
//	}
//};

// 4 version
class Solution
{
public:
	bool repeatedSubstringPattern(const std::string& s)
	{
		std::vector<int> prefix(1 + s.size(), 0);	// prefix[len] -> len
		for (int len = 2; len <= (int)s.size(); ++len)
		{
			int plen = prefix[len - 1];
			while (true)
			{
				if (s[plen] == s[len - 1])
				{
					plen++;
					break;
				}
				if (plen == 0)
					break;
				plen = prefix[plen];
			}
			prefix[len] = plen;
		}
		int period = (int)s.size() - prefix.back();
		return (period < (int)s.size() && s.size() % period == 0);		
	}
};

// 5 version

// 6 version

// 7 version


int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);


	return EXIT_SUCCESS;
}
