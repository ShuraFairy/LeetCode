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

// my version
//class Solution {
//public:
//    char findTheDifference(std::string s, std::string t)
//    {
//        if (s == "")
//            return t[0];
//        std::sort(begin(s), end(s));
//        std::sort(begin(t), end(t));
//        int i = 0;
//        std::cout << s << " " << t;
//        for (; i < s.size(); ++i)
//        {
//            if (s[i] != t[i])
//                return t[i];
//        }
//        return t[i];
//    }
//};


// 1 version
//class Solution 
//{
//public:
//    char findTheDifference(std::string s, std::string t) 
//    {
//        std::unordered_map<char, int> count;
//        for (char c : s)
//            count[c]--;
//        for (char c : t)
//            count[c]++;
//        for (auto kv : count)
//        {
//            if (kv.second == 1)
//                return kv.first;
//        }       
//        throw std::invalid_argument("");
//    }
//};

// 2 version
//class Solution
//{
//public:
//    char findTheDifference(std::string s, std::string t)
//    {
//        long long sum = 0;
//        for (char c : s)
//            sum -= c;
//        for (char c : t)
//            sum += c;
//        return (char)sum;
//    }
//};

// 3 version
class Solution
{
public:
    char findTheDifference(std::string s, std::string t)
    {
        char ans = 0;
        for (char c : s)
            ans ^= c;
        for (char c : t)
            ans ^= c;
        return ans;
    }
};

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
