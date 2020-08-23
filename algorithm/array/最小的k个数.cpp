/*
题目：输入n个整数，找出其中最小的k个数
解法：小顶堆
*/
#include <set>
#include <vector>

typedef std::multiset<int, std::greater<int>> intSet;
typedef std::multiset<int, std::greater<int>>::iterator setIt;
void GetLastNumbers(std::vector<int> data, intSet& lastnums, int k)
{
    lastnums.clear();
    if (k < 1 || data.size() < k)
    {
        return;
    }
    std::vector<int>::iterator iter = data.begin();
    for (; iter < data.end(); iter++)
    {
        if (lastnums.size() < k)
        {
            /* code */
            lastnums.insert(*iter);
        }
        else
        {
            setIt it = lastnums.begin();
            if (*iter < *(lastnums.begin()))
            {
                lastnums.erase(it);
                lastnums.insert(*iter);
            }
        }
        
    }
    
}