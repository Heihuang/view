/***
 * 题目：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 ***/
/****
 * 思路：数组中有一个数字出现的次数超过了数组长度的一半，如果把这个数组排序，那么排序之后位于数组中间的数字一定就是那个
 * 次数超过数组长度一半的数字，即中位数。
 * ****/
#include "../head.h"

int Partition(int data[], int len, int l, int r)
{
    if (data == nullptr || len <= 0 || l < 0 || r>=len)
    {
        /* code */
        return -1;
    }
    //定义主元
    int pod = RandomInRange(l, r);
    int sml = l - 1;
    //遍历数组，将小于主元的值放在数组左侧，将大于主元的值放在数组右侧
    for (size_t i = 0; i < len; i++)
    {
        if (data[i] < data[pod])
        {
            ++sml;
            Swap(&data[i], &data[sml]);
        }
    }
    ++sml;
    Swap(&data[sml], &data[pod]);
    return sml;
}

bool CheckInvalidArray(int* numbers, int len)
{
    return true;
}

bool CheckMoreThanHalf(int* numbers, int len, int num)
{
    int times = 0;
    for (int i = 0; i < len; i++)
    {
        if (numbers[i] == num)
        {
            times++;
        }
        
    }
    bool ismt = true;
    if (times * 2 <= len)
    {
        /* code */
        ismt = false;
    }
    return ismt;

}

int MoreThanHalfNum(int* numbers, int len)
{
    if (!CheckInvalidArray(numbers, len))
    {
        /* code */
        return 0;
    }
    int middle = len >> 1;
    int start = 0;
    int end = len - 1;
    int index = Partition(numbers, len, start, end);
    //找到中位数
    while (index != middle)
    {
        /* code */
        if (index > middle)
        {
            /* code */
            end = index - 1;
            index = Partition(numbers, len, start, end);
        }
        else
        {
            start = index + 1;
            index = Partition(numbers, len, start, end);
        }
    }
    int result = numbers[middle];
    if (CheckMoreThanHalf(numbers, len, result))
    {
        return result;
    }
    return 0;
}

//解法2:在遍历数组时保持两个值，一个是数组的数字，一个是次数，当遍历到下一个数字的时候，如果下一个数字和之前保存的数字
//相同，则次数加1；如果下一个数字和之前保存的不同，则次数减1，如果次数为0，我们需要保存下一个数字，并把次数设置为1

int MoreThanHalfNum(int *numbers, int len)
{
    if (!CheckInvalidArray(numbers, len))
    {
        /* code */
        return 0;
    }
    int result = numbers[0];
    int times = 1;
    for (int i = 0; i < len; i++)
    {
        if (times == 0)
        {
            result = numbers[i];
            times = 1;
        }
        else if (numbers[i] == result)
        {
            /* code */
            times++;
        }
        else
        {
            times--;
        }   
    }
    if (CheckMoreThanHalf(numbers, len, result))
    {
        return result;
    }
    return 0;
}