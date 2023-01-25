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
class Solution 
{
    enum class State { UNDEF, GOOD, BAD };

public:
    std::string longestWord(std::vector<std::string>& words) 
    {
        std::unordered_map<std::string, State> state;
        for (const std::string& word : words)
            state[word] = State::UNDEF;
        for (const std::string& word : words)
        {
            if (state[word] == State::UNDEF)
            {
                for (int len = (int)word.size() - 1; len >= 0; len--)
                {
                    if (len == 0)
                    {
                        for (int len = 1; len <= (int)word.size(); ++len)
                            state[word.substr(0, len)] = State::GOOD;                        
                    }
                    else
                    {
                        auto it = state.find(word.substr(0, len));
                        if (it == state.end())
                        {
                            for (len = len + 1; len <= (int)word.size(); ++len)
                                state[word.substr(0, len)] = State::BAD;
                            break;
                        }
                        else if (it->second != State::UNDEF)
                        {
                            for (len = len + 1; len <= (int)word.size(); ++len)
                                state[word.substr(0, len)] = it->second;
                            break;
                        }
                    }
                }
            }
        }
        std::string best = "";
        for (const std::string& word : words)
        {
            if (
                (word.size() > best.size() || 
                (word.size() == best.size() && word < best)) && 
                 state[word] == State::GOOD)
            {
                best = word;
            }
        }
        return best;
    }
};

// 2 version
 
// 3 version

// 4 version

// 5 version

// 6 version

// 7 version

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    std::ios_base::sync_with_stdio(false);    
    std::cin.tie(nullptr);

    //Solution s;
    /*std::vector<int> a{ 4, 1, 2, 1, 2 };
    std::cout << s.singleNumber(a) << std::endl;*/

    return EXIT_SUCCESS;
}
