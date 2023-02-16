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

const int FASTIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

// 1 version
//class Solution 
//{
//public:
//    int majorityElement(std::vector<int>& a) 
//    {
//        std::unordered_map<int, size_t> count;
//        for (int v : a)
//            count[v]++;
//        size_t need = a.size() / 2 + 1;
//        for (const auto & kv : count)
//        {
//            if (kv.second >= need)
//                return kv.first;
//        }
//        throw std::invalid_argument("invalid");
//    }
//};

// 2 version
//class Solution
//{
//public:
//    int majorityElement(std::vector<int>& a)
//    {
//        std::sort(begin(a), end(a));
//        size_t need = a.size() / 2 + 1;
//        size_t count = 0;
//        for (size_t i = 0; i < a.size(); ++i)
//        {
//            if (i == 0 || a[i] == a[i - 1])
//                count++;
//            else
//                count = 1;
//            if (count >= need)
//                return a[i];
//        }
//        throw std::invalid_argument("invalid");
//    }
//};

// 3 version
//class Solution
//{
//public:
//    int majorityElement(std::vector<int>& a)
//    {
//        std::sort(begin(a), end(a));
//        return a[a.size() / 2];        
//    }
//};

// 4 version
//class Solution
//{
//public:
//    int majorityElement(std::vector<int>& a)
//    {
//        std::mt19937 gen(2125);
//        size_t need = a.size() / 2 + 1;
//        while (true)
//        {
//            int value = a[std::uniform_int_distribution<size_t>(0, a.size() - 1)(gen)];
//            size_t count = 0;
//            for (int v : a)
//            {
//                if (v == value)
//                    count++;
//            }
//            if (count >= need)
//                return value;
//        }
//    }
//};

// 5 version
//class Solution
//{
//public:
//    int majorityElement(std::vector<int>& a)
//    {
//        int cand = 0;
//        size_t count = 0;
//        for (int v : a)
//        {
//            if (v == cand)
//                count++;
//            else
//            {
//                if (count == 0)
//                {
//                    cand = v;
//                    count = 1;
//                }
//                else
//                    count--;
//            }
//        }
//        assert(count > 0);
//        return cand;
//    }
//};

// 5 version
class Solution
{
public:
    int majorityElement(std::vector<int>& a)
    {
        std::nth_element(a.begin(), a.begin() + a.size() / 2, a.end());
        return a[a.size() / 2];
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
