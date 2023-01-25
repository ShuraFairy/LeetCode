#include <iostream>
#include <vector>
#include <cassert>
#include <type_traits>

//// 1 version
//class Solution 
//{
//public:
//
//    bool isLetter(char c)
//    {
//        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
//    }
//
//    std::string reverseOnlyLetters(const std::string s) 
//    {
//        std::string res = s;
//        int dst = static_cast<int>(res.size()) - 1;
//        for (int src = 0; src < static_cast<int>(res.size()); ++src)
//        {
//            if (isLetter(s[src]))
//            {
//                while (!isLetter(res[dst]))
//                {
//                    --dst;
//                    assert(dst >= 0);
//                }
//                res[dst] = s[src];
//                dst--;
//            }
//        }
//
//        return res;
//    }
//};

// 2 version
class Solution 
{
public:

    bool isLetter(char c)
    {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
    }

    std::string reverseOnlyLetters(std::string s) 
    {
        int i = 0;
        int j = static_cast<int>(s.size()) - 1;
        while (true)
        {
            while (i < j && !isLetter(s[i]))
            {
                i++;
            }
            while (i < j && !isLetter(s[j]))
            {
                j--;
            }
            if (i < j)
            {
                std::swap(s[i], s[j]);
                i++;
                j--;
            }
            else
                break;
        }

        return std::move(s);
    }
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    std::string str{ "a-bC-dEf-ghIj" };
    Solution s;
    std::string res = s.reverseOnlyLetters(str);

    std::cout << res << std::endl;


	return EXIT_SUCCESS;
}
