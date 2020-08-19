
#include "../head.h"

void adjustHeap(int* arr, int i, int len)
{
    //取出当前元素,最终将temp放在合适的位置
    int temp = arr[i];
    //从i的左子节点开始，即2i+1开始
    for (int k = 2*i+1; k < len; k=k*2+1)
    {
        if(k+1 < len)
        {
            //如果左子节点大于右子节点，则k移动到右节点
            if(arr[k] < arr[k+1])
            {
                ++k;
            }
            //如果k节点的大于父节点，则将k节点的值赋值给父节点
            if (arr[k] > temp)
            {
                arr[i] = arr[k];
                i = k;
            }
            else
            {
                break;
            }
        }
    }
    arr[i] = temp;
}

void hsort(int* arr, int len)
{
    //第一步，构建大顶堆
    for(int i = (len / 2 - 1); i >= 0; --i)
    {
        //从下至上 从右至左，从第一个非叶子节点开始
        adjustHeap(arr, i, len);
    }
    //第二步，将剩余的n-1个元素依次构建
    for (int j = len - 1; j >= 0; --j)
    {
        //将堆顶元素与末尾元素交换
        Swap(&arr[0], &arr[j]);
        //重新构建堆
        adjustHeap(arr, 0, j);
        
    }
    
}