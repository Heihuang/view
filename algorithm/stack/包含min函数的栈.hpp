#include "../../head.h"
template <typename T> 
void Push(const T& v) 
{
    data.push(v);
    if (min_s.size() == 0 || value < min_s.top())
    {
        min_s.push(v);
    }
    else
    {
        min_s.push(min_s.top());
    }
}

void Pod()
{
    data.pop();
    min_s.pop();
}

const T& Top()
{
    return min_s.top();
}