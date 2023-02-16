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

// my version
//class MinStack {
//public:
//    MinStack() {
//
//    }
//
//    void push(int val)
//    {
//        v.push_back(val);
//    }
//
//    void pop() {
//        v.pop_back();
//    }
//
//    int top() {
//        if (!v.empty())
//            return v.back();
//        else
//            return 0;
//    }
//
//    int getMin() {
//        if (v.empty())
//            return 0;
//        std::vector<int>::const_iterator it = std::min_element(v.begin(), v.end());
//        return *it;
//    }
//private:
//    std::vector<int> v;
//
//};

// 1 version
//class MinStack 
//{
//    std::stack<int, std::list<int>> value;
//    std::stack<int, std::list<int>> min;
//
//public:
//
//    MinStack() { }
//    
//    void push(int val) 
//    {
//        if (value.empty() && min.empty())
//        {
//            value.push(val);
//            min.push(val);
//        }
//        else
//        {
//            value.push(val);
//            min.push(std::min(val, min.top()));
//        }
//    }
//
//    void pop() {
//        if (value.empty() && min.empty())
//            throw std::logic_error("pop from empty stack");
//        value.pop();
//        min.pop();
//    }
//
//    int top() const 
//    {
//        if (value.empty() && min.empty())
//            throw std::logic_error("top from empty stack");
//        return value.top();
//    }
//
//    int getMin() 
//    {
//        if (value.empty() && min.empty())
//            throw std::logic_error("empty stack");
//        return min.top();
//    }
//};

// 2 version
//class MinStack
//{
//    std::stack<int, std::vector<int>> value;
//    std::stack<int, std::vector<int>> min;
//
//public:
//
//    MinStack() { }
//
//    void push(int val)
//    {
//        if (value.empty() && min.empty())
//        {
//            value.push(val);
//            min.push(val);
//        }
//        else
//        {
//            value.push(val);
//            min.push(std::min(val, min.top()));
//        }
//    }
//
//    void pop() {
//        if (value.empty() && min.empty())
//            throw std::logic_error("pop from empty stack");
//        value.pop();
//        min.pop();
//    }
//
//    int top() const
//    {
//        if (value.empty() && min.empty())
//            throw std::logic_error("top from empty stack");
//        return value.top();
//    }
//
//    int getMin()
//    {
//        if (value.empty() && min.empty())
//            throw std::logic_error("empty stack");
//        return min.top();
//    }
//};
 
// 3 version
template<typename T, size_t SIZE = 16>
class BigList
{
    struct Leaf
    {
        T a[SIZE];
        Leaf* next;
        int filled;
    };
    
    Leaf* top;

public:
    typedef T value_type;
    typedef T & reference;
    typedef const T& const_reference;
    typedef size_t size_type;

    BigList() : top(nullptr) { }
    void push_back(const T& value)
    {
        if (top == nullptr || top->filled == SIZE)
        {
            Leaf* newTop = new Leaf();
            newTop->next = top;
            newTop->filled = 0;
            top = newTop;
        }
        top->a[top->filled] = value;
        top->filled++;
    }

    void pop_back()
    {
        assert(top != nullptr);
        assert(top->filled != 0);
        top->filled--;
        if (top->filled == 0)
        {
            Leaf* oldTop = top;
            top = oldTop->next;
            delete oldTop;
        }
    }

    T& back() 
    {
        assert(top != nullptr);
        assert(top->filled != 0);
        return top->a[top->filled - 1];
    }

    const T& back() const
    {
        assert(top != nullptr);
        assert(top->filled != 0);
        return top->a[top->filled - 1];
    }

    bool empty() const
    {
        return top == nullptr;
    }
};

class MinStack 
{
    struct Item
    {
        int value;
        int min;
    };
    std::stack<Item, BigList<Item>> st;
public:
    MinStack() {

    }

    void push(int val) {
        if (st.empty())
            st.push(Item{ val, val });
        else
            st.push(Item{ val, std::min(val, st.top().min) });
    }

    void pop() {
        if (st.empty())
            throw std::logic_error("top from empty stack");
        return st.pop();
    }

    int top() 
    {
        if (st.empty())
            throw std::logic_error("top from empty stack");
        return st.top().value;
    }

    int getMin() {
        if (st.empty() )
            throw std::logic_error("empty stack");
        return st.top().min;
    }
};

// 4 version

// 5 version

// 6 version

// 7 version

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    std::ios_base::sync_with_stdio(false);    
    std::cin.tie(nullptr);

    MinStack* obj = new MinStack();    
    obj->push(1);
    obj->pop();
//    int param_3 = obj->top();
//    int param_4 = obj->getMin();

//    Solution s;
    std::vector<int> a{ 0, 0, 2, 1 };
    std::vector<int> ans;
//    ans = s.addToArrayForm(a, 34);
//    std::cout << s.isPowerOfTwo(1) << std::endl;
//    std::cout << s.isPowerOfTwo(16) << std::endl;
//    std::cout << s.isPowerOfTwo(3) << std::endl;

    return EXIT_SUCCESS;
}
