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
//    int getHeight(TreeNode* node, int& ans)
//    {
//        if (node == nullptr)
//            return -1;
//        int leftH = getHeight(node->left, ans) + 1;
//        int rightH = getHeight(node->right, ans) + 1;
//        int path = leftH + rightH;
//        ans = std::max(ans, path);
//        return std::max(leftH, rightH);
//    }
//
//public:
//    int diameterOfBinaryTree(TreeNode* root) 
//    {
//        int ans = 0;
//        getHeight(root, ans);
//        return ans;
//    }
//};

// 2 version
//struct Node
//{
//    Node * next[3];
//    Node(Node * n1, Node * n2, Node * n3) : next{n1, n2, n3}
//    { }
//};
//class Solution
//{
//    Node* convert(TreeNode* oldNode, TreeNode * parent, Node * newParent)
//    {
//        if (oldNode == nullptr)
//            return nullptr;
//        Node* newNode = new Node(newParent, nullptr, nullptr);
//        newNode->next[1] = convert(oldNode->left, oldNode, newNode);
//        newNode->next[2] = convert(oldNode->right, oldNode, newNode);
//        return newNode;
//    }
//
//    void visit(Node* node, Node* parent, int dist, Node*& farthest, int& maxDist)
//    {
//        if (node == nullptr)
//            return;
//        if (dist > maxDist)
//        {
//            maxDist = dist;
//            farthest = node;
//        }
//        for (Node* next : node->next)
//        {
//            if (next != parent)
//                visit(next, node, dist + 1, farthest, maxDist);
//        }
//    }
//
//public:
//    int diameterOfBinaryTree(TreeNode* oldRoot)
//    {
//        Node* root = convert(oldRoot, nullptr, nullptr);
//        Node* endpoint1 = nullptr;
//        int maxDist = 0;
//        visit(root, nullptr, 0, endpoint1, maxDist);
//        Node* endpoint2 = nullptr;
//        int ans = 0;
//        visit(endpoint1, nullptr, 0, endpoint2, ans);
//        return ans;
//    }
//};

// 3 version
struct Node
{
    Node* next[3];
    Node(Node* n1, Node* n2, Node* n3) : next{ n1, n2, n3 }
    { }
};
class Solution
{
    Node* convert(TreeNode* oldNode, /*TreeNode* parent,*/ Node* newParent)
    {
        if (oldNode == nullptr)
            return nullptr;
        Node* newNode = new Node(newParent, nullptr, nullptr);
        newNode->next[1] = convert(oldNode->left, newNode);
        newNode->next[2] = convert(oldNode->right, newNode);
        return newNode;
    }

    void visit(Node* node, Node* parent, int dist, int& maxDist)
    {
        if (node == nullptr)
            return;
        if (dist > maxDist)
        {
            maxDist = dist;            
        }
        for (Node* next : node->next)
        {
            if (next != parent)
                visit(next, node, dist + 1, maxDist);
        }
    }

    int findMax(Node* node, Node* parent)
    {
        if (node == nullptr)
            return 0;
        int maxDist = 0;
        visit(node, nullptr, 0, maxDist);
        for (Node* next : node->next)
        {
            if (next != parent)
                maxDist = std::max(maxDist, findMax(next, node));
        }
        return maxDist;
    }

public:
    int diameterOfBinaryTree(TreeNode* oldRoot)
    {
        Node* root = convert(oldRoot, nullptr);        
        return findMax(root, nullptr);
    }
};

// 4 version

// 5 version

// 6 version


int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    std::ios_base::sync_with_stdio(false);    
    std::cin.tie(nullptr);

//    Solution s;
    /*std::vector<int> a{ 4, 1, 2, 1, 2 };
    std::cout << s.singleNumber(a) << std::endl;*/

    return EXIT_SUCCESS;
}
