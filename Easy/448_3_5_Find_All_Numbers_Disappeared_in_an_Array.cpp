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
//    std::vector<int> findDisappearedNumbers(std::vector<int>& a) 
//    {
//        for (int x : a)
//        {
//            int i = std::abs(x) - 1;
//            if (a[i] > 0)
//                a[i] = -a[i];
//        }
//        std::vector<int> ans;
//        for (int v = 1; v <= static_cast<int>(a.size()); ++v)
//        {
//            int i = v - 1;
//            if (a[i] > 0)
//                ans.push_back(v);
//        }
//        return ans;
//    }
//};

// 2 version
class Solution
{
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& a)
    {
        for (int i = 0; i < static_cast<int>(a.size()); ++i)
        {
            while (true)
            {
                int j = a[i] - 1;
                if (a[j] == a[i])
                    break;
                std::swap(a[i], a[j]);
            }
        }
        std::vector<int> ans;
        for (int i = 0; i < static_cast<int>(a.size()); ++i)
        {
            if (a[i] != i + 1)
                ans.push_back(i + 1);
        }
        return ans;
    }
};

// 3 version

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
