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

const int FASTIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

// 1 version
//class Solution 
//{
//public:
//    std::vector<int> fairCandySwap(std::vector<int>& a, std::vector<int>& b) 
//    {
//        int sumA = 0;
//        for (auto elem : a)
//            sumA += elem;
//        int sumB = 0;
//        for (auto elem : b)
//            sumB += elem;
//        
//        for (int av : a)
//        {
//            for (int bv : b)
//            {
//                if (sumA - av + bv == sumB - bv + av)
//                    return std::vector<int>{av, bv};
//            }
//        }
//        throw std::invalid_argument("no solution for given A and B");
//    }
//};

// 2 version
//class Solution
//{
//public:
//    std::vector<int> fairCandySwap(std::vector<int>& a, std::vector<int>& b)
//    {
//        int sumA = 0;
//        for (auto elem : a)
//            sumA += elem;
//        int sumB = 0;
//        std::unordered_set<int> bValues;
//        for (auto elem : b)
//        {
//            sumB += elem;
//            bValues.insert(elem);
//        }
//        assert((sumA - sumB) % 2 == 0);
//        int diff = (sumA - sumB) / 2;
//
//        for (int av : a)
//        {
//            int bv = av - diff;
//            if (bValues.count(bv) > 0)
//                return std::vector<int>{av, bv};
//        }
//        throw std::invalid_argument("no solution for given A and B");
//    }
//};

// 3 version
//class IntSet
//{
//    std::vector<int> a;
//public:
//    IntSet(int capacity) : a(capacity * 2, 0)
//    {
//
//    }
//
//    void insert(int value)
//    {
//        int pos = value % static_cast<int>(a.size());
//        while (true)
//        {
//            if (a[pos] == value)
//                return;
//            if (a[pos] == 0)
//            {
//                a[pos] = value;
//                return;
//            }
//            pos = (pos + 1 + value % 997) % static_cast<int>(a.size());
//        }
//    }
//
//    int count(int value) const
//    {
//        int pos = value % static_cast<int>(a.size());
//        while (true)
//        {
//            if (a[pos] == value)
//                return 1;
//            if (a[pos] == 0)
//                return 0;
//            pos = (pos + 1 + value % 997) % static_cast<int>(a.size());
//        }
//    }
//};
//
//class Solution
//{
//public:
//    std::vector<int> fairCandySwap(std::vector<int>& a, std::vector<int>& b)
//    {
//        int sumA = 0;
//        for (auto elem : a)
//            sumA += elem;
//        int sumB = 0;
//        IntSet bValues(b.size());
//        for (auto elem : b)
//        {
//            sumB += elem;
//            bValues.insert(elem);
//        }
//        assert((sumA - sumB) % 2 == 0);
//        int diff = (sumA - sumB) / 2;
//
//        for (int av : a)
//        {
//            int bv = av - diff;
//            if (bValues.count(bv) > 0)
//                return std::vector<int>{av, bv};
//        }
//        throw std::invalid_argument("no solution for given A and B");
//    }
//};

// 4 version
//class Solution
//{
//public:
//    std::vector<int> fairCandySwap(std::vector<int>& a, std::vector<int>& b)
//    {
//        int sumA = 0;
//        for (auto elem : a)
//            sumA += elem;
//        int sumB = 0;
//        std::sort(b.begin(), b.end());
//        for (auto elem : b)        
//            sumB += elem;        
//        assert((sumA - sumB) % 2 == 0);
//        int diff = (sumA - sumB) / 2;
//
//        for (int av : a)
//        {
//            int bv = av - diff;
//            if (std::binary_search(b.begin(), b.end(), bv))
//                return std::vector<int>{av, bv};
//        }
//        throw std::invalid_argument("no solution for given A and B");
//    }
//};

// 5 version
class Solution
{
public:
    std::vector<int> fairCandySwap(std::vector<int>& a, std::vector<int>& b)
    {
        std::sort(a.begin(), a.end());
        int sumA = 0;
        for (auto elem : a)
            sumA += elem;
        int sumB = 0;
        std::sort(b.begin(), b.end());
        for (auto elem : b)
            sumB += elem;
        assert((sumA - sumB) % 2 == 0);
        int diff = (sumA - sumB) / 2;
        int bi = 0;
        for (int av : a)
        {
            int bv = av - diff;
            while (bi < (int)b.size() && b[bi] < bv)
            {
                bi++;
            }

            if (bi < (int)b.size() && b[bi] == bv)
                return std::vector<int>{av, bv};
        }
        throw std::invalid_argument("no solution for given A and B");
    }
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    std::ios_base::sync_with_stdio(false);    
    std::cin.tie(nullptr);

    Solution s;
    /*std::vector<int> a{ 4, 1, 2, 1, 2 };
    std::cout << s.singleNumber(a) << std::endl;*/

    return EXIT_SUCCESS;
}
