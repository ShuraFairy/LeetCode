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
#include <functional>

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

// https://www.youtube.com/watch?v=wNuRONENMe4

// my version

// 1 version
//class Solution 
//{
//public:
//    bool isAnagram(std::string s, std::string t) 
//	{
//		std::sort(s.begin(), s.end());
//		std::sort(t.begin(), t.end());
//		return s == t;
//    }
//};

// 2 version
//class Solution
//{
//public:
//	bool isAnagram(const std::string & s, const std::string & t)
//	{
//		if (s.size() != t.size())
//			return false;
//		size_t count['z' - 'a' + 1] = {};
//		for (char c : s)
//			count[c - 'a']++;
//		for (char c : t)
//		{
//			size_t & v = count[c - 'a'];
//			if (v == 0)
//				return false;
//			v--;
//		}
//		return true;
//	}
//};

// 3 version
//class Solution
//{
//public:
//	bool isAnagram(const std::string& s, const std::string& t)
//	{
//		if (s.size() != t.size())
//			return false;
//		size_t count['z' + 1] = {};
//		for (char c : s)
//			count[c]++;
//		for (char c : t)
//		{
//			count[c]--;
//		}
//		for (char c = 'a'; c <= 'z'; ++c)
//			if (count[c] != 0)
//				return false;
//		return true;
//	}
//};
// 4 version
class Solution
{
public:
	bool isAnagram(const std::string& s, const std::string& t)
	{
		if (s.size() != t.size())
			return false;
		std::unordered_map<char, size_t> count;
		for (char c : s)
			++count[c];
		for (char c : t)
			--count[c];
		for (const auto& kv : count)
		{
			if (kv.second != 0)
				return false;
		}
	
		return true;
	}
};

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
