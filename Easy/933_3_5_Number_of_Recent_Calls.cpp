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
//class RecentCounter 
//{
//private:
//    std::queue<int> q;
//public:
//    RecentCounter() = default;
//
//    int ping(int t) 
//    {        
//        q.push(t);
//        while (q.front() < t - 3000)
//        {
//            q.pop();
//        }
//        return static_cast<int>(q.size());
//    }
//};

template <typename T, size_t MAX_SIZE>
class MaxSizeQueue
{
    T arr[MAX_SIZE];
    size_t first;
    size_t after;
    size_t count;
public:
    MaxSizeQueue() : first(0), after(0), count(0)
    { }

    void push(const T& value)
    {
        assert(count < MAX_SIZE);
        arr[after] = value;
        after++;
        if (after == MAX_SIZE)
            after = 0;
        count++;
    }

    const T& front() const
    {
        assert(count > 0);
        return arr[first];
    }

    void pop()
    {
        assert(count > 0);
        first++;
        if (first == MAX_SIZE)
            first = 0;
        count--;
    }

    size_t size() const
    {
        return count;
    }
};

// 2 version
class RecentCounter 
{
private:
    MaxSizeQueue<int, 3002> q;
public:
    RecentCounter() = default;
    
    int ping(int t) 
    {        
        q.push(t);
        while (q.front() < t - 3000)
        {
            q.pop();
        }
        return static_cast<int>(q.size());
    }
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    //std::vector<int> v{ 0,10,5,2 };//{ 0,2,1,0 };
    //Solution s;
    //std::cout << s.peakIndexInMountainArray(v) << std::endl;

	return EXIT_SUCCESS;
}
