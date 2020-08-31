/*
题目描述：请实现一个函数，输入一个整数，输出该数二进制表示中 1 的个数。例如，
把 9 表示成二进制是 1001，有 2 位是 1。因此，如果输入 9，则该函数输出 2
解法：(n−1) 解析： 二进制数字n最右边的 1变成 0，此1右边的0都变成 1
*/

int hammingWeight(uint32_t n) 
{
    int res = 0;
    while(n){
        res++;
        //lowbit
        n-=n&(-n);
    }
    return res;
}
