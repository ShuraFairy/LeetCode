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

// https://www.youtube.com/watch?v=ucCArP5ZJtg

// my version

// 1 version
//class Solution 
//{
//public:
//    int romanToInt(std::string_view  s) 
//	{
//		std::unordered_map<char, int> romanToValue = {
//			{'I', 1},
//			{'V', 5},
//			{'X', 10},
//			{'L', 50},
//			{'C', 100},
//			{'D', 500},
//			{'M', 1000}
//		};
//		int ans = 0;
//		int prev = INT_MAX;
//		for (char c : s)
//		{
//			int value = romanToValue[c];
//			if (value <= prev)
//				ans += value;
//			else
//			{
//				ans += value;
//				ans -= 2 * prev;
//			}
//			prev = value;
//		}
//		return ans;
//    }
//};

// 2 version
// M CM CD C XC XL X IX IV I
class Solution
{
public:
	int romanToInt(std::string_view  s)
	{	
		assert(s != "");
		int ans = 0;
		std::function<bool(std::string_view, int)> removePrefix = [&](std::string_view prefix, int value)
			{
				//if (s.size() >= prefix.size() && s.substr(0, prefix.size()) == prefix)
				if (s.starts_with(prefix))
				{
					ans += value;
					s = s.substr(prefix.size());
					return true;
				}
				else
					return false;
			};
		removePrefix("MMM", 3000) ||
		removePrefix("MM", 2000) ||
		removePrefix("M", 1000);

		removePrefix("CM", 900) || 
		removePrefix("DCCC", 800) ||
		removePrefix("DCC", 700) ||
		removePrefix("DC", 600) ||
		removePrefix("D", 500) ||
		removePrefix("CD", 400) ||
		removePrefix("CCC", 300) ||
		removePrefix("CC", 200) ||
		removePrefix("C", 100);

		removePrefix("XC", 90) ||
		removePrefix("LXXX", 80) ||
		removePrefix("LXX", 70) ||
		removePrefix("LX", 60) ||
		removePrefix("L", 50) ||
		removePrefix("XL", 40) ||
		removePrefix("XXX", 30) ||
		removePrefix("XX", 20) ||
		removePrefix("X", 10);

		removePrefix("IX", 9) ||
		removePrefix("VIII", 8) ||
		removePrefix("VII", 7) ||
		removePrefix("VI", 6) ||
		removePrefix("V", 5) ||
		removePrefix("IV", 4) ||
		removePrefix("III", 3) ||
		removePrefix("II", 2) ||
		removePrefix("I", 1);
		assert(s == "");

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
