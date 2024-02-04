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

// https://www.youtube.com/watch?v=VvEujIgV-D0

// my version

// 1 version
//class Solution 
//{
//	int compare(const std::string& left, const std::string& right, const std::vector<int>& pos)
//	{
//		for (int i = 0; i < static_cast<int>(left.size()) && i < static_cast<int>(right.size()); ++i)
//		{
//			int diff = pos[left[i] - 'a'] - pos[right[i] - 'a'];
//			if (diff != 0)
//				return diff;			
//		}
//		return static_cast<int>(left.size()) - static_cast<int>(right.size());
//	}
//public:
//    bool isAlienSorted(const std::vector<std::string> & words, const std::string & order) 
//	{
//		std::vector<int> pos('z' - 'a' + 1);
//		for (int i = 0; i < static_cast<int>(order.size()); ++i)
//			pos[order[i] - 'a'] = i;
//		for (int i = 1; i < static_cast<int>(words.size()); ++i)
//		{
//			if (compare(words[i - 1], words[i], pos) > 0)
//				return false;
//		}
//		return true;	
//    }
//};

// 2 version
class Solution
{
	int compare(const std::string& left, const std::string& right, const std::string & order)
	{
		for (int i = 0; i < static_cast<int>(left.size()) && i < static_cast<int>(right.size()); ++i)
		{
			int diff = static_cast<int>(order.find(left[i])) - static_cast<int>(order.find(right[i]));
			if (diff != 0)
				return diff;
		}
		return static_cast<int>(left.size()) - static_cast<int>(right.size());
	}
public:
	bool isAlienSorted(const std::vector<std::string>& words, const std::string& order)
	{	
		for (int i = 1; i < static_cast<int>(words.size()); ++i)
		{
			if (compare(words[i - 1], words[i], order) > 0)
				return false;
		}
		return true;
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
