#include <ios>
#include <iostream>
#include <vector>
#include <cassert>
#include <type_traits>
#include <tuple>
#include <deque>
#include <queue>

const int FASTIO = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

// 1 version
//class Solution
//{
//public:
//    std::vector<int> shortestToChar(const std::string & s, char c) 
//    {
//        const int INF = static_cast<int>(s.size());
//        std::vector<int> result(s.size(), INF);
//        int dist = INF;
//        for (int i = 0; i < static_cast<int>(s.size()); ++i)
//        {
//            if (s[i] == c)
//                dist = 0;
//            else
//                dist++;
//            result[i] = dist;
//        }
//        dist = INF;
//        for (int i = static_cast<int>(s.size()) - 1; i >= 0; --i)
//        {
//            if (s[i] == c)
//                dist = 0;
//            else
//                dist++;
//            result[i] = std::min(result[i], dist);
//        }
//
//        return result;
//    }
//};

// 2 version
class Solution
{
public:
    std::vector<int> shortestToChar(const std::string& s, char c)
    {        
        std::vector<int> result(s.size(), 0);
        int pos = 0;
        for (int i = 0; i < static_cast<int>(s.size()); ++i)
        {
            if (s[i] == c)
            {
                pos = i;
                break;
            }
        }
        for (int i = 1; i <= pos; ++i)
        {
            result[pos - i] = i;
        }
        for (int i = pos + 1; i < static_cast<int>(s.size()); ++i)
        {
            if (s[i] == c)
            {
                if (i > pos + 1)
                {
                    int value = 1;
                    int i1 = pos + 1;
                    int i2 = i - 1;
                    while (true)
                    {
                        result[i1] = value;
                        if (i1 == i2)
                        {
                            break;
                        }
                        i1++;
                        result[i2] = value;
                        if (i1 == i2)
                        {
                            break;
                        }
                        i2--;
                        value++;
                    }
                }
                pos = i;
            }
        }
        for (int i = pos + 1; i < static_cast<int>(s.size()); ++i)
        {
            result[i] = i - pos;
        }

        return result;
    }
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    std::string str{ "loveleetcode" };
    std::vector<int> v;
    Solution s;
    v = s.shortestToChar(str, 'e');
    for (const auto& elem : v)
        std::cout << elem << ", ";

	return EXIT_SUCCESS;
}
