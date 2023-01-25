#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <cctype>

class Solution 
{
public:

    int peakIndexInMountainArray(std::vector<int>& arr) 
    {
        std::vector<int>::size_type size = arr.size();
        int indexPeak = 0;
        int max = 0;

        for (size_t i = 0; i < size; ++i)
        {
            if (max < arr[i])
            {
                max = arr[i];
                indexPeak = i;
            }
        }

        return indexPeak;
    }
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{    
    std::vector<int> v{ 0,10,5,2 };//{ 0,2,1,0 };
    Solution s;
    std::cout << s.peakIndexInMountainArray(v) <<  std::endl;

	return EXIT_SUCCESS;
}
