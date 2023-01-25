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
class Solution 
{
public:
    void moveZeroes(std::vector<int>& v) 
    {
        size_t size1 = v.size();
        v.erase(std::remove(v.begin(), v.end(), 0), v.end());
        size_t size2 = v.size();

        int sizero = size1 - size2;

        for (int i = 0; i < sizero; ++i)
            v.push_back(0);
    }
};

// 2 version

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
