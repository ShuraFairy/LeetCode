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
//class Solution 
//{
//public:
//    bool isAlphaNum(char c)
//    {
//        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');;
//    }
//
//    bool toLower(char c)
//    {
//        if ('A' <= c && c <= 'Z')
//            return static_cast<char>(c - 'A' + 'a');
//        else
//            return c;
//    }
//
//    bool isPalindrome(const std::string & s) 
//    {
//        std::string::size_type size = s.size();
//        int i = 0;
//        int j = static_cast<int>(size) - 1;
//        while (true)
//        {
//            while (i < j && !isalnum(static_cast<unsigned char>(s[i])))
//            {
//                i++;
//            }
//            while (i < j && !isalnum(static_cast<unsigned char>(s[j])))
//            {
//                j--;
//            }
//            if (i < j)
//            {
//                if (tolower(static_cast<unsigned char>(s[i])) != 
//                    tolower(static_cast<unsigned char>(s[j])))
//                {
//                    return false;
//                }
//                i++;
//                j--;
//            }
//            else
//                return true;
//        }
//
//        return true;
//    }
//};

// 2 version
//class Solution 
//class Solution
//{
//public:
//    bool isAlphaNum(char c)
//    {
//        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');;
//    }
//
//    char toLower(char c)
//    {
//        if ('A' <= c && c <= 'Z')
//            return static_cast<char>(c - 'A' + 'a');
//        else
//            return c;
//    }
//
//    bool isPalindrome(const std::string& s)
//    {
//        std::string::size_type size = s.size();
//        int i = 0;
//        int j = static_cast<int>(size) - 1;
//        while (true)
//        {
//            while (i < j && !isAlphaNum((s[i])))
//            {
//                i++;
//            }
//            while (i < j && !isAlphaNum((s[j])))
//            {
//                j--;
//            }
//            if (i < j)
//            {
//                if (toLower((s[i])) !=
//                    toLower((s[j])))
//                {
//                    return false;
//                }
//                i++;
//                j--;
//            }
//            else
//                return true;
//        }
//
//        return true;
//    }
//};

// 3 version
class Solution
{
public:

    bool isLetterOrNumber(char c)
    {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');;
    }

    bool isPalindrome(std::string s)
    {
        std::string::size_type size = s.size();
        std::string temp;
        temp.reserve(size);

        for (size_t i = 0; i < size; ++i)
        {
            if (isLetterOrNumber(s[i]))
            {
                temp.push_back(s[i]);
            }
        }

        for (size_t i = 0, j = 0; i < temp.size() / 2;)
        {
            if (std::toupper(temp[i]) == std::toupper(temp[temp.size() - 1 - j]))
            {
                i++; j++;
                continue;
            }
            else
                return false;
        }
        return true;
    }
};


int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    std::string str{ "A man, a plan, a canal : Panama"};
    //std::string str{ "a." };// { "0P" };
    Solution s;
    bool res = s.isPalindrome(str);

    std::cout << std::boolalpha << res << std::endl;

	return EXIT_SUCCESS;
}
