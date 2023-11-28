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
//	bool isIsomorphic(const std::string & s, const std::string & t) 
//	{
//		assert(s.size() == t.size());
//		std::vector<int> sToT(128, -1);
//		std::vector<int> tToS(128, -1);
//		for (size_t i = 0; i < s.size(); ++i)
//		{
//			char sc = s[i];
//			char tc = t[i];
//			assert(0 <= sc && sc <= 127);
//			assert(0 <= tc && tc <= 127);
//			if (sToT[sc] == tc && tToS[tc] == sc)
//			{
//				// ok
//			}
//			else if (sToT[sc] == -1 && tToS[tc] == -1)
//			{
//				sToT[sc] = tc;
//				tToS[tc] = sc;
//			}
//			else
//				return false;
//		}
//		return true;
//	}
//};

// 2 version
class Solution
{
public:
	bool isIsomorphic(const std::string& s, const std::string& t)
	{
		assert(s.size() == t.size());
		std::unordered_map<char, char> sToT;
		std::unordered_map<char, char> tToS;
		for (size_t i = 0; i < s.size(); ++i)
		{
			char sc = s[i];
			char tc = t[i];	
			auto s_iter = sToT.find(sc);
			auto t_iter = tToS.find(tc);
			if (s_iter == sToT.end() && t_iter == tToS.end())
			{
				sToT[sc] = tc;
				tToS[tc] = sc;
			}
			else if (s_iter == sToT.end() || t_iter == tToS.end())
			{
				return false;
			}
			else if (s_iter->second == tc && t_iter->second == sc)
			{
				// ok
			}
			else
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

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int && a = 1;
	int b = 1;
	int c = std::move(a);

	std::cout << "a: " << a << "\n";
	std::cout << "c: " << c << "\n";
	c = std::move(b);
	std::cout << "b: " << b << "\n";
	std::cout << "c: " << c << "\n";

	Solution s;
	//std::cout << s.reverseBits(3) << std::endl;

	int* p1 = (int*)malloc(4 * sizeof(int));
	free(p1);

	return EXIT_SUCCESS;
}

