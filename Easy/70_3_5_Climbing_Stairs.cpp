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
#include <set>
#include <string>

#pragma push_macro("assert")
#undef assert
#pragma pop_macro("assert")

const int FASTIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();


// Definition for a binary tree node.
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
// 1 version
//class Solution 
//{
//public:
//    int climbStairs(int n) 
//    {
//        int f[50];
//        f[1] = 1;
//        f[2] = 2;
//        for (int i = 3; i <= n; ++i)
//            f[i] = f[i - 1] + f[i - 2];
//        return f[n];
//    }
//};

// 2 version
//class Solution
//{
//public:
//    int climbStairs(int n)
//    {
//        if (n == 1)
//            return 1;
//        int prev = 1;
//        int curr = 2;
//        for (int i = 3; i <= n; ++i)
//        {
//            int next = prev + curr;
//            prev = curr;
//            curr = next;
//        }
//        
//        return curr;
//    }
//};
 
// 3 version
struct Matrix
{
    int a[2][2];
    friend Matrix operator * (const Matrix& left, const Matrix& right);
    Matrix(int a00, int a01, int a10, int a11) : a{ a00, a01, a10, a11 }
    { }
    static Matrix one()
    {
        // 1 0
        // 0 1
        return Matrix{ 1, 0, 0, 1 };
    }
    Matrix pow(int n) const
    {
        assert(n >= 0);
        if (n == 0)
            return one();
        else if (n % 2 == 0)
        {
            Matrix sqrt = this->pow(n / 2);
            return sqrt * sqrt;
        }
        else
            return *this * this->pow(n - 1);
    }
};

Matrix operator * (const Matrix& left, const Matrix& right)
{
    Matrix ans(0, 0, 0, 0);
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            for (int k = 0; k < 2; ++k)
            {
                ans.a[i][j] += left.a[i][k] * right.a[k][j];
            }
        }
    }
    return ans;
}
class Solution
{    
public:
    int climbStairs(int n)
    {
        Matrix p = Matrix(0, 1, 1, 1).pow(n - 1);
        return p.a[0][1] + p.a[1][1];        
    }
};

// 4 version

// 5 version

// 6 version

// 7 version

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    std::ios_base::sync_with_stdio(false);    
    std::cin.tie(nullptr);

    Solution s;
    std::vector<int> a{ 0, 0, 2, 1 };
    std::vector<int> ans;
//    ans = s.addToArrayForm(a, 34);

    return EXIT_SUCCESS;
}
