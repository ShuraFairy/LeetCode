#include <iostream>
#include <vector>
#include <cassert>
#include <string>

class Solution {
public:
    std::string reverseOnlyLetters(std::string s)
    {
        std::string::size_type size = s.size();

        int i = 0;
        int j = size - 1;;

        while (i < j)
        {
            if(((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) &&
                ((s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= 'a' && s[j] <= 'z')))
            std::swap(s[i], s[j]);
            else
            {               
                if (((s[i] < 'A' || s[i] > 'Z') || (s[i] < 'a' || s[i] > 'z')) &&
                    ((s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= 'a' && s[j] <= 'z')))
                {
                    i++;
                    continue;
                }
                if (((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) &&
                    ((s[j] < 'A' || s[j] > 'Z') || (s[j] < 'a' || s[j] > 'z')))
                {
                    j--;
                    continue;
                }
            }
            i++; j--;
        }
        return std::move(s);
    }
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    std::string str{"a-bC-dEf-ghIj"};
    Solution s; 
    std::string res = s.reverseOnlyLetters(str);

    std::cout << res << std::endl;
    

	return EXIT_SUCCESS;
}
