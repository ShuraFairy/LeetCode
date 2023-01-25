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
//class KthLargest 
//{
//    std::priority_queue<int, std::vector<int>, std::greater<int>> topK;
//    int k;
//public:
//    KthLargest(int k, std::vector<int>& a) : k(k)
//    {
//        for (int v : a)
//        {
//            topK.push(v);
//            if (topK.size() > k)
//                topK.pop();
//        }
//    }
//
//    int add(int val) 
//    {
//        topK.push(val);
//        if (topK.size() > k)
//            topK.pop();
//        assert(topK.size() == k);
//        
//        return topK.top();
//    }
//};

// 2 version
//class KthLargest
//{
//    std::multiset<int> topK;
//    int k;
//public:
//    KthLargest(int k, std::vector<int>& a) : k(k)
//    {
//        for (int v : a)
//        {
//            topK.insert(v);
//            if (topK.size() > k)
//                topK.erase(topK.begin());
//        }
//    }
//
//    int add(int val)
//    {
//        if (topK.size() == k && val <= *topK.begin())
//            return *topK.begin();
//        topK.insert(val);
//        if (topK.size() > k)
//            topK.erase(topK.begin());
//        assert(topK.size() == k);
//
//        return *topK.begin();
//    }
//};

// 3 version
//class KthLargest 
//{
//    std::priority_queue<int, std::vector<int>, std::greater<int>> topK;
//    int k;
//public:
//    KthLargest(int k, std::vector<int>& a) : k(k)
//    {
//        for (int v : a)
//        {
//            topK.push(v);
//            if (topK.size() > k)
//                topK.pop();
//        }
//    }
//
//    int add(int val) 
//    {
//        if (topK.size() == k && val <= topK.top())
//            return topK.top();
//        topK.push(val);
//        if (topK.size() > k)
//            topK.pop();
//        assert(topK.size() == k);
//        
//        return topK.top();
//    }
//};

// 4 version
//class KthLargest
//{
//    std::vector<int> topK;
//    int k;
//public:
//    KthLargest(int k, std::vector<int>& a) : k(k), topK(a)
//    {
//        if (topK.size() > k)
//        {
//            std::nth_element(topK.begin(), topK.begin() + k, topK.end(), std::greater<int>());
//            topK.resize(k);
//        }
//    }        
//
//    int add(int val)
//    {
//        topK.push_back(val);
//        if (topK.size() > k)
//        {
//            auto minIt = std::min_element(topK.begin(), topK.end());
//            std::swap(*minIt, *--topK.end());
//            topK.pop_back();
//        }
//        
//        assert(topK.size() == k);
//
//        return *std::min_element(topK.begin(), topK.end());
//    }
//};

// 5 version
//class KthLargest
//{
//    std::vector<int> a;
//    int k;
//public:
//    KthLargest(int k, std::vector<int>& a) : k(k), a(a)
//    { }
//
//    int add(int val)
//    {
//        a.push_back(val);        
//        std::nth_element(a.begin(), a.begin() + k - 1, a.end(), std::greater<int>());        
//
//        return a[k - 1];
//    }
//};

// 6 version
class KthLargest
{
    std::vector<int> a;
    int k;
public:
    KthLargest(int k, std::vector<int>& a) : k(k), a(a)
    { }

    int add(int val)
    {
        a.push_back(val);
        std::sort(a.begin(), a.end(), std::greater<int>());

        return a[k - 1];
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
