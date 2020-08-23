/*
题目：输入一个整数n，求从1到n，这n个整数的十进制表示中1出现的次数
解法：每次去掉最高位做递归
*/
#include <stdio.h>
#include <string.h>

int NumberOfN(int n)
{
    if (n <= 0)
    {
        /* code */
        return 0;
    }
    char strN[50];
    sprintf(strN, "%d", n);
}

int NumOf1(const char* strN)
{
    if (!strN || *strN < '0' || *strN > '9' || *strN == '\0')
    {
        /* code */
        return 0;
    }
    int first = *strN - '0';
    unsigned int len = static_cast<unsigned int>(strlen(strN));
    if (len == 1 && first == 0)
    {
        /* code */
        return 0;
    }
    if (len == 1 && first > 0)
    {
        /* code */
        return 1;
    }
    int numFirstDigit = 0;
    if (first > 1)
    {
        /* code */
        numFirstDigit = PowerBase10(len - 1);
    }
    else if (first == 1)
    {
        /* code */
        numFirstDigit = atoi(strN + 1) + 1;
    }
    int numOtherDigits = first * (len+1) * PowerBase10(len - 2);
    int numRecursive = NumOf1(strN + 1);
    return numFirstDigit + numOtherDigits + numRecursive;
}