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
class Solution 
{
public:
    std::string addStrings(const std::string & a1, const std::string & a2) 
	{
		std::string res;
		res.reserve(std::max(a1.size(), a2.size()) + 1);
		int carry = 0;
		int i1 = (int)a1.size() - 1;
		int i2 = (int)a2.size() - 1;
		while (i1 >= 0 || i2 >= 0 || carry > 0)
		{
			if (i1 >= 0)
			{
				carry += a1[i1] - '0';
				--i1;
			}
			if (i2 >= 0)
			{
				carry += a2[i2] - '0';
				--i2;
			}
			res.push_back(char(carry % 10 + '0'));
			carry /= 10;
		}
		assert(i1 < 0 && i2 < 0 && carry == 0);
		std::reverse(res.begin(), res.end());
		assert(res.size() == 1 || (res.size() > 1 && res[0] != '0'));
		return res;
    }
};

// 2 version

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
