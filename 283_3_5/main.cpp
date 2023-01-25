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
//    void moveZeroes(std::vector<int>& a) 
//    {
//        std::vector<int>::size_type size = a.size();
//        for (int i = 0; i < static_cast<int>(size); ++i)
//        {
//            if (a[i] != 0)
//            {
//                int j = i - 1;
//                while (j >= 0 && a[j] == 0)
//                {
//                    std::swap(a[j], a[j + 1]);
//                    j--;
//                }
//            }
//        }
//    }
//};

// 2 version
//class Solution
//{
//public:
//    void moveZeroes(std::vector<int>& a)
//    {
//        std::vector<int>::size_type size = a.size();
//
//        int i = 0;
//        while (i < size && a[i] != 0)
//        {
//            i++;
//        }
//        int j = i;
//
//        for (; i < static_cast<int>(size); ++i)
//        {
//            if (a[i] != 0)
//            {
//                std::swap(a[i], a[j]);
//                j++;
//            }
//        }
//    }
//};

// 3 version
class Solution
{
public:
    void moveZeroes(std::vector<int>& a)
    {
        std::vector<int>::size_type size = a.size();

        int i = 0;
        while (i < size && a[i] != 0)
        {
            i++;
        }
        int j = i;

        for (; i < static_cast<int>(size); ++i)
        {
            if (a[i] != 0)
            {
                a[j] = a[i];
                j++;
            }
        }
        for (; j < static_cast<int>(size); ++j)
        {
            a[j] = 0;
        }
    }
};

// 4 version

// 5 version

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    std::ios_base::sync_with_stdio(false);    
    std::cin.tie(nullptr);

    Solution s;
    /*std::vector<int> a{ 4, 1, 2, 1, 2 };
    std::cout << s.singleNumber(a) << std::endl;*/

    return EXIT_SUCCESS;
}
