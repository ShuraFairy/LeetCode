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
//    int countBinarySubstrings(const std::string & s) 
//    {
//        int count = 0;
//        std::string::size_type size = s.size();
//        for (int left = 0; left < size; ++left)
//        {
//            for (int right = left + 1; right < size; right += 2)
//            {
//                char first = s[left];
//                char last = s[right];               
//                if (first != last)
//                {
//                    int midRight = left + (right - left + 1) / 2;
//                    int midLeft = midRight - 1;
//                    bool good = true;
//                    for (int i = left; i <= midLeft && good; ++i)
//                    {
//                        if (s[i] != first)
//                        {
//                            good = false;                           
//                        }
//                    }
//                    for (int i = midRight; i <= right && good; ++i)
//                    {
//                        if (s[i] != last)
//                        {
//                            good = false;
//                        }
//                    }
//                    if (good)
//                        count++;
//                }
//            }
//        }
//        return count;
//    }
//};

// 2 version
class Solution
{
public:
    int countBinarySubstrings(const std::string& s)
    {
        int count = 0;
        int prevSize = 0;
        int curSize = 0;
        int curC = '$';
        for (char c : s)
        {
            if (c == curC)
                curSize++;
            else
            {
                count += std::min(prevSize, curSize);
                prevSize = curSize;
                curC = c;
                curSize = 1;
            }
        }
        count += std::min(prevSize, curSize);
        
        return count;
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
