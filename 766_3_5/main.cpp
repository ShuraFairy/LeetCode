#include <cassert>
#include <deque>
#include <ios>
#include <iostream>
#include <queue>
#include <tuple>
#include <type_traits>
#include <vector>

const int FASTIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

// 1 version
//class Solution 
//{
//public:
//    bool isToeplitzMatrix(const std::vector<std::vector<int>>& matrix) 
//    {
//        int sizeI = static_cast<int>(matrix.size());
//        int sizeJ = static_cast<int>(matrix[0].size());
//        for (int i = 0; i < sizeI; ++i)
//        {
//            for (int j = 0; j < sizeJ; ++j)
//            {
//                if (i == 0 || j == 0)
//                {
//                    int value = matrix[i][j];
//                    int ii = i + 1;
//                    int jj = j + 1;
//                    while (ii < sizeI && jj < sizeJ)
//                    {
//                        if (matrix[ii][jj] != value)
//                            return false;
//                        ii++;
//                        jj++;
//                    }
//                }
//            }
//        }
//        return true;
//    }
//};

// 2 version
//class Solution
//{
//public:
//    bool isToeplitzMatrix(const std::vector<std::vector<int>>& matrix)
//    {
//        int sizeI = static_cast<int>(matrix.size());
//        int sizeJ = static_cast<int>(matrix[0].size());
//        for (int i = 1; i < sizeI; ++i)
//        {
//            for (int j = 1; j < sizeJ; ++j)
//            {
//                if (matrix[i][j] != matrix[i - 1][j - 1])
//                    return false;
//            }
//        }
//        return true;
//    }
//};

// 3 version
class Solution
{
public:
    bool isToeplitzMatrix(const std::vector<std::vector<int>>& matrix)
    {
        const long long b = 101;
        const long long p = 1000 * 1000 * 1000 + 7;
        long long prevH = 0;        
        int sizeI = static_cast<int>(matrix.size());
        int sizeJ = static_cast<int>(matrix[0].size());
        
        for (int i = 0; i < sizeI; ++i)
        {
            long long pow = 1;
            int matrixi0 = 0;
            long long h = 0;
            for (int j = 0; j < sizeJ; ++j)
            {
                if (i == 0)
                {
                    if (j + 1 < sizeJ)
                    {
                        h += matrix[i][j] * pow;
                        h %= p;
                        pow *= b;
                        pow %= p;
                    }
                    else
                    {
                        prevH = h;
                    }
                }
                else
                {
                    assert(i > 0);
                    if (j == 0)
                    {
                        matrixi0 = matrix[i][j];
                    }
                    else if (j + 1 < sizeJ)
                    {
                        h += matrix[i][j] * pow;
                        h %= p;
                        pow *= b;
                        pow %= p;
                    }
                    else
                    {
                        if (prevH != (h + matrix[i][j] * pow) % p)
                            return false;
                        prevH = (matrixi0 + h * b) % p;
                    }
                }
            }
        }
        return true;
    }
};

// 4 version

// 5 version

int main([[maybe_unused]] int argc, [[maybe_unused]] char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    return EXIT_SUCCESS;
}
