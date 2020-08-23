/*
题目：输入一个整型数组，数组里有正数也有负数。数组中一个连续的多个正数组成一个子数组。求所有子数组的和的最大值。
解法：从头到尾逐个累加数组中每个数字，如果从第一个开始的子数组和小于从后面第某个数字开始的子数组和，抛弃之前的累加和
*/

int FindGreatestSumOfSubArray(int* data, int len)
{
    if (data == nullptr || len <=0)
    {
        return 0;
    }
    int cusum = 0;
    int greatsum = 0x80000000;
    for (int i = 0; i < len; i++)
    {
        /* code */
        if (cusum <= 0)
        {
            cusum = data[i];
        }
        else
        {
            cusum += data[i];
        }
        if (cusum > greatsum)
        {
            greatsum = cusum;
        }
    }
    return greatsum;
}