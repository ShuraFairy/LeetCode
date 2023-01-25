#include <ios>
#include <iostream>
#include <vector>
#include <cassert>
#include <type_traits>
#include <tuple>

const int FASTIO = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

// 1 version
class Solution 
{
public:
    int peakIndexInMountainArray(std::vector<int>& arr) 
    {
        std::vector<int>::size_type size = arr.size();
        int left = 0;
        int right = size - 1;
        while (right - left > 2)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] < arr[mid + 1])
                left = mid;
            else
                right = mid + 1;
        }
        assert(right - left == 2);
        
        return left + 1;
    }
};

// 2 version
//class Solution 
//{
//public:
//    int peakIndexInMountainArray(std::vector<int>& arr) 
//    {
//
//    }
//};

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    std::vector<int> v{ 0,10,5,2 };//{ 0,2,1,0 };
    Solution s;
    std::cout << s.peakIndexInMountainArray(v) << std::endl;

	return EXIT_SUCCESS;
}
