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

const int FASTIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

// 1 version
class Solution 
{
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) 
    {
        std::stack<int, std::vector<int>> greater;
        std::vector<int>::size_type size2 = nums2.size();
        std::unordered_map<int, int> numToAns;

        for (int i = (int)size2 - 1; i >= 0; i--)
        {
            while (!greater.empty() && greater.top() < nums2[i])
                greater.pop();
            if (greater.empty())
                numToAns[nums2[i]] = -1;
            else
                numToAns[nums2[i]] = greater.top();
            greater.push(nums2[i]);
        }
        std::vector<int> ans(nums1.size());
        for (int i = 0; i < (int)nums1.size(); ++i)
        {
            ans[i] = numToAns[nums1[i]];
        }

        return ans;
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
