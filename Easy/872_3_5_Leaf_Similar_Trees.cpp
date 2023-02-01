#include <cassert>
#include <deque>
#include <ios>
#include <iostream>
#include <queue>
#include <tuple>
#include <type_traits>
#include <vector>

const int FASTIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right)
    {
    }
};

// 1 version
// class Solution
//{
//    void getLeaves(TreeNode* node, std::vector<int>& leaves)
//    {
//        if (node == nullptr)
//            return;
//        if (node->left == nullptr && node->right == nullptr)
//        {
//            leaves.push_back(node->val);
//            return;
//        }
//        getLeaves(node->left, leaves);
//        getLeaves(node->right, leaves);
//    }
//
// public:
//    bool leafSimilar(TreeNode* root1, TreeNode* root2)
//    {
//        std::vector<int> leaves1;
//        getLeaves(root1, leaves1);
//        std::vector<int> leaves2;
//        getLeaves(root2, leaves2);
//
//        return (leaves1 == leaves2);
//    }
//};

// 2 version
//class Solution
//{
//    void getLeaves(TreeNode* node, std::vector<int>& leaves)
//    {
//        if (node == nullptr)
//            return;
//        if (node->left == nullptr && node->right == nullptr)
//        {
//            leaves.push_back(node->val);
//            return;
//        }
//        getLeaves(node->left, leaves);
//        getLeaves(node->right, leaves);
//    }
//
//    bool isSimilar(TreeNode* node, const std::vector<int> &leaves, int &pos)
//    {
//        if (node == nullptr)
//            return true;
//        if (node->left == nullptr && node->right == nullptr)
//        {
//            if (pos < static_cast<int>(leaves.size()) && leaves[pos] == node->val)
//            {
//                pos++;
//                return true;
//            }
//            else
//                return false;
//        }
//        return (isSimilar(node->left, leaves, pos) && isSimilar(node->right, leaves, pos));
//    }    
//
//  public:
//    bool leafSimilar(TreeNode *root1, TreeNode *root2)
//    {
//        std::vector<int> leaves1;
//        getLeaves(root1, leaves1);
//        int pos1 = 0;
//        bool similar = isSimilar(root2, leaves1, pos1);
//
//        return (similar && pos1 == static_cast<int>(leaves1.size()));
//    }
//};

// 3 version
//class Solution 
//{
//    TreeNode* getLeavesList(TreeNode* node, TreeNode* stack)
//    {
//        if (node == nullptr)
//            return stack;
//        if (node->left == nullptr && node->right == nullptr)
//        {
//            node->right = stack;            
//            return node;
//        }
//        stack = getLeavesList(node->right, stack);
//        stack = getLeavesList(node->left, stack);
//        return stack;
//    }
//
//    bool areEqual(TreeNode* list1, TreeNode* list2)
//    {
//        while (true)
//        {
//            if (list1 == nullptr && list2 == nullptr)
//                return true;
//            if (list1 == nullptr || list2 == nullptr)
//                return false;
//            if (list1->val != list2->val)
//                return false;
//            list1 = list1->right;
//            list2 = list2->right;
//        }
//    }
//
//    void clear(TreeNode* list)
//    {
//        while (list != nullptr)
//        {
//            TreeNode* node = list;
//            list = list->right;
//            node->right = nullptr;
//        }
//    }
//
//public:
//    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
//    {
//        TreeNode* list1 = getLeavesList(root1, nullptr);
//        TreeNode* list2 = getLeavesList(root2, nullptr);
//        bool similar = areEqual(list1, list2);
//        clear(list1);
//        clear(list2);
//        return similar;
//    }
//};

// 4 version
//class Solution
//{
//    TreeNode* getLeavesList(TreeNode* node, TreeNode* stack)
//    {
//        if (node == nullptr)
//            return stack;
//        if (node->left == nullptr && node->right == nullptr)
//        {
//            node->right = stack;
//            return node;
//        }
//        stack = getLeavesList(node->right, stack);
//        stack = getLeavesList(node->left, stack);
//        return stack;
//    }    
//
//    void clear(TreeNode* list)
//    {
//        while (list != nullptr)
//        {
//            TreeNode* node = list;
//            list = list->right;
//            node->right = nullptr;
//        }
//    }
//
//    bool skipList(TreeNode* node, TreeNode*& list)
//    {
//        if (node == nullptr)
//            return true;
//        if (node->left == nullptr && node->right == nullptr)
//        {
//            if (list == nullptr)
//                return false;
//            if (node->val != list->val)
//                return false;
//            else
//            {
//                TreeNode* toClear = list;
//                list = list->right;
//                toClear->right = nullptr;
//                return true;
//            }
//        }
//
//        return skipList(node->left, list) && skipList(node->right, list);
//    }
//
//public:
//    bool leafSimilar(TreeNode* root1, TreeNode* root2)
//    {
//        TreeNode* list1 = getLeavesList(root1, nullptr);
//        bool skipped = skipList(root2, list1);
//        bool similar = skipped && list1 == nullptr;
//        clear(list1);        
//        return similar;
//    }
//};

// 5 version
class Solution 
{
    class  Iterator
    {
        std::vector<TreeNode*> path;

        void pathToFirst(TreeNode* root)
        {
            while (true)
            {
                path.push_back(root);
                if (root->left != nullptr)
                    root = root->left;
                else if (root->right != nullptr)
                    root = root->right;
                else
                    return;
            }
        }

    public:
        Iterator(TreeNode* root)
        {
            if (root == nullptr)
                return;
            pathToFirst(root);
        }
        bool hasNext() const
        {
            return !path.empty();

        }

        int next()
        {
            assert(!path.empty());
            TreeNode* answer = path.back();
            while (true)
            {
                TreeNode* last = path.back();
                path.pop_back();
                if (path.empty())
                    break;
                TreeNode* parent = path.back();
                if (parent->left == last)
                {
                    if (parent->right != nullptr)
                    {
                        pathToFirst(parent->right);
                        break;
                    }                    
                }
                else
                {
                    assert(parent->right == last);
                }
            }

            return answer->val;
        }
    };

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        Iterator it1(root1);
        Iterator it2(root2);
        while (true)
        {
            if (!it1.hasNext() && !it2.hasNext())
            {
                return true;
            }
            if (!it1.hasNext() || !it2.hasNext())
                return false;
            if (it1.next() != it2.next())
                return false;
        }
    }
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    return EXIT_SUCCESS;
}
