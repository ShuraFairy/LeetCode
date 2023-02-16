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
//    int addDigits(int num) 
//    {
//        if (num == 0)
//            return 0;
//        int res = num % 9;
//        if (res == 0)
//            return 9;
//        else
//            return res;
//    }
//};

// 2 version
class Solution
{
public:
    int addDigits(int num)
    {
        return (num - 1) % 9 + 1;
    }
};

// 3 version

// 4 version

// 5 version


int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    std::ios_base::sync_with_stdio(false);    
    std::cin.tie(nullptr);

//    Solution s;
    /*std::vector<int> a{ 4, 1, 2, 1, 2 };
    std::cout << s.singleNumber(a) << std::endl;*/

    return EXIT_SUCCESS;
}
