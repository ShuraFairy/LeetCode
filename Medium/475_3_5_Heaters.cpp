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
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// my version

// 1 version
//class Solution 
//{
//public:
//    int findRadius(const std::vector<int>& houses, const std::vector<int>& heaters) 
//    {
//        int ans = 0;
//        for (int house : houses)
//        {
//            int minDist = INT_MAX;
//            for (int heater : heaters)
//                minDist = std::min(minDist, std::abs(heater - house));
//            ans = std::max(ans, minDist);
//        }
//        return ans;
//    }
//};

// 2 version
//class Solution
//{
//public:
//    int findRadius(const std::vector<int>& houses, std::vector<int>& heaters)
//    {
//        if (houses.empty() && heaters.empty())
//            return 0;
//        assert(!heaters.empty());
//        std::sort(begin(heaters), end(heaters));
//        int ans = 0;
//        for (int house : houses)
//        {
//            int minDist = INT_MAX;
//            auto it = std::lower_bound(heaters.begin(), heaters.end(), house);
//            if (it != heaters.end())
//            {
//                int heater = *it;
//                minDist = std::min(minDist, std::abs(heater - house));
//            }
//            if (it != heaters.begin())
//            {
//                --it;
//                int heater = *it;
//                minDist = std::min(minDist, std::abs(heater - house));
//            }
//           
//            ans = std::max(ans, minDist);
//        }
//        return ans;
//    }
//};

// 3 version
class Solution
{
public:
    int findRadius(std::vector<int>& houses, std::vector<int>& heaters)
    {
        assert(!houses.empty());
        assert(!heaters.empty());
        std::sort(begin(houses), end(houses));
        std::sort(begin(heaters), end(heaters));
        int i = 0;
        int ans = 0;
        for (int house : houses)
        {
            while (i + 1 < (int)heaters.size() && heaters[i + 1] < house)
                ++i;
            int minDist = std::abs(heaters[i] - house);
            if (i + 1 < (int)heaters.size())
                minDist = std::min(minDist, std::abs(heaters[i + 1] - house));
            ans = std::max(ans, minDist);
            
        }
        return ans;
    }
};

// 4 version

// 5 version

// 6 version

// 7 version

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    std::ios_base::sync_with_stdio(false);    
    std::cin.tie(nullptr);        

    Solution s;
    //std::cout << s.reverseBits(3) << std::endl;
    
    int* p1 = (int*)malloc(4 * sizeof(int));
    free(p1);    

    return EXIT_SUCCESS;
}
