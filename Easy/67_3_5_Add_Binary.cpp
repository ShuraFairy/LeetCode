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
//	std::string addBinary(const std::string & a, const std::string & b) 
//	{
//		assert(!a.empty() && !b.empty());
//		std::vector<char> res;
//		
//		for(int carry = 0, ia = (int)a.size() - 1, ib = (int)b.size() - 1;
//			carry > 0 || ia >= 0 || ib >= 0; ia--, ib--)
//		{		
//			int sum = carry + (ia >= 0 ? a[ia] - '0' : 0) + 
//				(ib >=0 ? b[ib] - '0' : 0);
//			res.push_back(char((sum & 1) + '0'));
//			carry = (sum >> 1);
//		}
//		assert(!res.empty());
//		return std::string(res.rbegin(), res.rend());
//	}
//};

// 2 version
class Solution
{
public:
	std::string addBinary(const std::string& a, const std::string& b)
	{
		assert(!a.empty() && !b.empty());
		std::string res;

		for (int carry = 0, ia = (int)a.size() - 1, ib = (int)b.size() - 1;
			carry > 0 || ia >= 0 || ib >= 0; ia--, ib--)
		{
			int sum = carry + (ia >= 0 ? a[ia] - '0' : 0) +
				(ib >= 0 ? b[ib] - '0' : 0);
			res.push_back(char((sum & 1) + '0'));
			carry = (sum >> 1);
		}
		assert(!res.empty());
		std::reverse(res.begin(), res.end());
		return res;
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
