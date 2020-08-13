#include <exception>
#include <stdlib.h>
#include "../head.h"

int RandomInRange(int l, int r)
{
    int index = 0;
    srand(time(nullptr));
    index = l + rand()%r;
    return index;
}


int Partition(int data[], int length, int start, int end)
{
    if(data == NULL || length <= 0 || start < 0 || end >= length)
        return -1;
    int index = RandomInRange(start, end);
    //定义哨兵
    int pos = data[index];
    //定义最左端索引
    int samll = start - 1;
    for(index = start; index < end; ++index)
    {
        //当前值小于哨兵，左端索引加一，将当前值交换到左端索引位置
        if(data[index] < pos)
        {
            ++samll;
            if(samll != index)
            {
                Swap(&data[index], &data[samll]);
            }
        }
    }
    //第一趟遍历结束，左端索引加1，交换哨兵
    ++samll;
    Swap(&data[samll], &data[end]);
    return samll;
}

void QuickSort(int data[], int length, int start, int end)
{
    if(start == end)
        return;
    int index = Partition(data, length, start, end);
    if(index > start)
        QuickSort(data, length, start, index - 1);
    if(index < end)
        QuickSort(data, length, index+1, end);
}