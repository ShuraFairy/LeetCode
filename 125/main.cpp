#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <cctype>

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
       
        for (size_t i = 0, j = 0; i < temp.size()/2;)
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
    //std::string str{ "A man, a plan, a canal : Panama"};
    std::string str{ "a." };// { "0P" };
    Solution s; 
    bool res = s.isPalindrome(str);

    std::cout << std::boolalpha << res << std::endl;    

	return EXIT_SUCCESS;
}
