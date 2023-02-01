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
 
// 1 version
//class Solution 
//{
//public:
//    int maximumProduct(std::vector<int>& a) 
//    {
//        int ans = INT_MIN;
//        for (int i = 0; i < (int)a.size(); ++i)
//        {
//            for (int j = i + 1; j < (int)a.size(); ++j)
//            {
//                for (int k = j + 1; k < (int)a.size(); ++k)
//                {
//                    ans = std::max(ans, a[i] * a[j] * a[k]);
//                }
//            }
//        }
//        return ans;
//    }
//};

// 2 version
//class Solution
//{
//public:
//    int maximumProduct(std::vector<int>& a)
//    {       
//        for (int i = 0; i < (int)a.size(); ++i)
//        {
//            for (int j = a.size() - 2; j >= i; j--)
//            {
//                if (a[j + 1] < a[j])
//                    std::swap(a[j], a[j + 1]);
//            }
//        }
//        int sz = (int)a.size();
//        return std::max(a[0] * a[1] * a[sz - 1], a[sz - 3] * a[sz - 2] * a[sz - 1]);
//    }
//};
 
// 3 version
//class Solution
//{
//public:
//    int maximumProduct(std::vector<int>& a)
//    {
//        for (int i = 0; i < (int)a.size(); ++i)
//        {
//            int min = a[i];
//            int minI = i;
//            for (int j = i + 1; j < (int)a.size(); j++)
//            {
//                if (a[j] < min)
//                {
//                    min = a[j];
//                    minI = j;
//                }
//            }
//            std::swap(a[i], a[minI]);
//        }
//        int sz = (int)a.size();
//        return std::max(a[0] * a[1] * a[sz - 1], a[sz - 3] * a[sz - 2] * a[sz - 1]);
//    }
//};

// 4 version
//class Solution
//{
//public:
//    int maximumProduct(std::vector<int>& a)
//    {
//        int max1 = INT_MIN;
//        int max2 = INT_MIN;
//        int max3 = INT_MIN;
//        int min1 = INT_MAX;
//        int min2 = INT_MAX;
//       
//        for (int v : a)
//        {
//            if (v > max1)
//            {
//                max3 = max2;
//                max2 = max1;
//                max1 = v;
//            }
//            else if (v > max2)
//            {
//                max3 = max2;
//                max2 = v;
//            }
//            else if (v > max3)
//                max3 = v;
//            if (v < min1)
//            {
//                min2 = min1;
//                min1 = v;
//            }
//            else if (v < min2)
//                min2 = v;
//        }       
//                
//        return std::max(min1 * min2 * max1, max3 * max2 * max1);
//    }
//};

// 5 version
//class Solution
//{
//public:
//    int maximumProduct(std::vector<int>& a)
//    {
//        std::swap(a[a.size() - 1], *std::max_element(a.begin(), a.end()));
//        std::swap(a[a.size() - 2], *std::max_element(a.begin(), a.end() - 1));
//        std::swap(a[a.size() - 3], *std::max_element(a.begin(), a.end() - 2));
//        std::swap(a[0], *std::min_element(a.begin(), a.end()));
//        std::swap(a[1], *std::min_element(a.begin() + 1, a.end()));
//
//        int sz = (int)a.size();
//        return std::max(a[0] * a[1] * a[sz - 1], a[sz - 3] * a[sz - 2] * a[sz - 1]);
//    }
//};

// 6 version
//class Solution
//{
//public:
//    int maximumProduct(std::vector<int>& a)
//    {
//        std::priority_queue<int, std::vector<int>, std::greater<int>> max3;
//        std::priority_queue<int> min2;
//        for (int v : a)
//        {
//            max3.push(v);
//            if (max3.size() > 3)
//                max3.pop();
//            min2.push(v);
//            if (min2.size() > 2)
//                min2.pop();
//        }
//        int a1 = min2.top();
//        min2.pop();
//        int a0 = min2.top();
//        int am3 = max3.top();
//        max3.pop();
//        int am2 = max3.top();
//        max3.pop();
//        int am1 = max3.top();
//
//        return std::max(a0 * a1 * am1, am3 * am2 * am1);
//    }
//};

// 7 version
class Solution
{
public:
    int maximumProduct(std::vector<int>& a)
    {
        std::multiset<int> max3;
        std::multiset<int> min2;
        for (int v : a)
        {
            max3.insert(v);
            if (max3.size() > 3)
                max3.erase(max3.begin());
            min2.insert(v);
            if (min2.size() > 2)
                min2.erase(--min2.end());
        }
        int a0 = *min2.begin();
        int a1 = *++min2.begin();
        int am3 = *max3.begin();
        int am2 = *++max3.begin();
        int am1 = *++(++max3.begin());

        return std::max(a0 * a1 * am1, am3 * am2 * am1);
    }
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    std::ios_base::sync_with_stdio(false);    
    std::cin.tie(nullptr);

    //Solution s;
    /*std::vector<int> a{ 4, 1, 2, 1, 2 };
    std::cout << s.singleNumber(a) << std::endl;*/

    return EXIT_SUCCESS;
}
