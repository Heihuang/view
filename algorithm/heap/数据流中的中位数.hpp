/*
题目：如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值
void addNum(int num) - 从数据流中添加一个整数到数据结构中
double findMedian() - 返回目前所有元素的中位数
解法：给定一长度为 N 的无序数组，其中位数的计算方法：首先对数组执行排序（使用O(NlogN)时间，
然后返回中间元素即可（使用O(1) 时间）
建立一个 小顶堆 A 和 大顶堆 B，各保存列表的一半元素，且规定：
A 保存较大的一半，长度为N/2(N为偶数)或（N+1）/2(N为奇数)
B 保存较小的一半，长度为N/2(N为偶数)或（N+1）/2(N为奇数)
*/
/*addNum(num) 函数
当 m=n（即 N 为 偶数）：需向 A 添加一个元素。实现方法：将新元素 num 插入至 B ，再将 B 堆顶元素插入至 A ；
当 m!=n（即 N 为 奇数）：需向 B 添加一个元素。实现方法：将新元素 num 插入至A ，再将 
A 堆顶元素插入至 B*/

/*
findMedian() 函数：
当 m=n（N 为 偶数）：则中位数为 （A的堆顶元素+B的堆顶元素)/2
当 m!=n（N为奇数）：则中位数为A的堆顶元素
*/
#include <queue>
using namespace std;
priority_queue<int> lo;                              // 大顶堆
priority_queue<int, vector<int>, greater<int>> hi;   // 小顶堆

void addNum(int num)
{
    lo.push(num);                                    // 加到大顶堆

    hi.push(lo.top());                               // 平衡
    lo.pop();

    if (lo.size() < hi.size()) {                     // 维护两个堆元素个数
        lo.push(hi.top());
        hi.pop();
    }
}

// Returns the median of current data stream
double findMedian()
{
    return lo.size() > hi.size() ? (double) lo.top() : (lo.top() + hi.top()) * 0.5;
}
