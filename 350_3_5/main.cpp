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
//    std::vector<int> intersect(const std::vector<int>& aa, const std::vector<int>& bb) 
//    {
//        const std::vector<int>& a = aa.size() < bb.size() ? aa : bb;
//        const std::vector<int>& b = aa.size() < bb.size() ? bb : aa;
//        std::unordered_map<int, int> count;
//        for (int v : a)
//            count[v]++;
//        std::vector<int> ans;
//        for (int v : b)
//        {
//            auto it = count.find(v);
//            if (it != count.end() && it->second > 0)
//            {
//                ans.push_back(v);
//                it->second--;
//            }
//        }
//        return ans;
//    }
//};

// 2 version
//struct Pair
//{
//    int num;
//    int count;
//};
//class Solution
//{
//public:
//    std::vector<int> intersect(const std::vector<int>& aa, const std::vector<int>& bb)
//    {
//        const std::vector<int>& a = aa.size() < bb.size() ? aa : bb;
//        const std::vector<int>& b = aa.size() < bb.size() ? bb : aa;
//        std::vector<int> ans;
//        std::vector<Pair> pairs;
//        pairs.reserve(a.size());
//        for (int v : a)
//            pairs.push_back(Pair{ v, 1 });
//        std::sort(pairs.begin(), pairs.end(), [](const Pair& left, const Pair& right)
//            {
//                return left.num < right.num;
//            });
//        int last = -1;
//        for (int i = 0; i < (int)pairs.size(); ++i)
//        {
//            if (last >= 0 && pairs[i].num == pairs[last].num)
//                pairs[last].count++;
//            else
//            {
//                last++;
//                pairs[last] = pairs[i];
//            }
//        }
//        pairs.resize(last + 1);
//        for (int v : b)
//        {
//            auto it = std::lower_bound(pairs.begin(), pairs.end(), v, [](const Pair& p, int v)
//                {
//                    return p.num < v;
//                });
//            if (it != pairs.end() && it->num == v && it->count > 0)
//            {
//                ans.push_back(v);
//                it->count--;
//            }
//        }
//        
//        return ans;
//    }
//};

// 3 version
//struct Pair
//{
//    int num;
//    bool present;
//};
//class Solution
//{
//public:
//    std::vector<int> intersect(const std::vector<int>& aa, const std::vector<int>& bb)
//    {
//        const std::vector<int>& a = aa.size() < bb.size() ? aa : bb;
//        const std::vector<int>& b = aa.size() < bb.size() ? bb : aa;
//        std::vector<int> ans;
//        std::vector<Pair> pairs;
//        pairs.reserve(a.size());
//        for (int v : a)
//            pairs.push_back(Pair{ v, true });
//        std::sort(pairs.begin(), pairs.end(), [](const Pair& left, const Pair& right)
//            {
//                return left.num < right.num;
//            });
//        
//        for (int v : b)
//        {
//            auto it = std::lower_bound(pairs.begin(), pairs.end(), v, [](const Pair& p, int v)
//                {
//                    return p.num < v || p.num == v && !p.present;
//                });
//            if (it != pairs.end() && it->num == v)
//            {
//                assert(it->present);
//                ans.push_back(v);
//                it->present = false;
//            }
//        }
//
//        return ans;
//    }
//};

// 4 version
//class Solution
//{
//public:
//    std::vector<int> intersect(std::vector<int>& a, std::vector<int>& b)
//    {        
//        std::vector<int> ans;
//        std::sort(begin(a), end(a));
//        std::sort(begin(b), end(b));
//        size_t ia = 0;
//        size_t ib = 0;
//        while (ia < a.size() && ib < b.size())
//        {
//            if (a[ia] < b[ib])
//                ia++;
//            else if (b[ib] < a[ia])
//                ib++;
//            else
//            {
//                ans.push_back(a[ia]);
//                ia++;
//                ib++;
//            }
//        }
//     
//        return ans;
//    }
//};

// 5 version
class HashMap
{
    const int FREE = -1;
    std::vector<int> keys;
    std::vector<int> values;
    
public:
    HashMap(size_t size) : keys(size + size / 2 + 1), values(size + size / 2 + 1, FREE)
    { }
    void inc(int key)
    {
        size_t h = key % keys.size();
        while (true)
        {
            if (values[h] == FREE)
            {
                keys[h] = key;
                values[h] = 1;
                return;
            }
            if (keys[h] == key)
            {                
                values[h]++;
                return;
            }
            h++;
            if (h == values.size())
                h = 0;
        }
    }
    bool dec(int key)
    {
        size_t h = key % keys.size();
        while (true)
        {
            if (values[h] == FREE)
                return false;
            if (keys[h] == key)
            {
                if (values[h] > 0)
                {
                    values[h]--;
                    return true;
                }
                else
                    return false;            
            }
            h++;
            if (h == values.size())
                h = 0;
        }
    }
};
class Solution 
{
public:
    std::vector<int> intersect(const std::vector<int>& aa, const std::vector<int>& bb) 
    {
        const std::vector<int>& a = aa.size() < bb.size() ? aa : bb;
        const std::vector<int>& b = aa.size() < bb.size() ? bb : aa;
        HashMap count(a.size());
        for (int v : a)
            count.inc(v);
        std::vector<int> ans;
        for (int v : b)
        {
            if(count.dec(v))
                ans.push_back(v);             
            
        }
        return ans;
    }
};

// 6 version


int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    std::ios_base::sync_with_stdio(false);    
    std::cin.tie(nullptr);

    Solution s;
    /*std::vector<int> a{ 4, 1, 2, 1, 2 };
    std::cout << s.singleNumber(a) << std::endl;*/

    return EXIT_SUCCESS;
}
