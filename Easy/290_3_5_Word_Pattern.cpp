#include <cstdio>   
#include <cstdlib> 
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

// Definition for singly - linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}    
};

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

// my version

// 1 version
class Solution 
{
public:
    bool wordPattern(const std::string & letters, const std::string & words) 
    {
        if (letters.empty() && words.empty())
            return true;
        if (letters.empty() || words.empty())
            return false;
        std::unordered_map<char, std::string> letterToWord;
        std::unordered_map<std::string, char> wordToLetter;
        int wordStartPos = 0;
        assert('a' <= words[0] && words[0] <= 'z');
        int letterPos = 0;
        for (int i = 1; i <= (int)words.size(); ++i)
        {
            if (i == (int)words.size() || words[i] == ' ')
            {
                std::string word = words.substr(wordStartPos, i - wordStartPos);
                wordStartPos = i + 1;
                if (letterPos == letters.size())
                    return false;
                char letter = letters[letterPos];
                letterPos++;
                auto wordIt = wordToLetter.find(word);
                auto letterIt = letterToWord.find(letter);
                if (wordIt == wordToLetter.end())
                {
                    if (letterIt != letterToWord.end())
                        return false;
                    wordToLetter[word] = letter;
                    letterToWord[letter] = word;
                }
                else
                {
                    if (letterIt == letterToWord.end())
                        return false;
                    if (wordIt->second != letter || letterIt->second != word)
                        return false;
                }                
            }
        }
        return letterPos == (int)letters.size();
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

    Solution s;
    //std::cout << s.reverseBits(3) << std::endl;
    
    int* p1 = (int*)malloc(4 * sizeof(int));
    free(p1);    

    return EXIT_SUCCESS;
}
