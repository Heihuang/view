/*
题目描述：给定一个数组A[0,1,…,n-1],请构建一个数组B[0,1,…,n-1],
其中B中的元素B[i]=A[0]A[1]…*A[i-1]A[i+1]…*A[n-1],不能使用除法
解题思路：B[i] 就是 A[i] 左边所有元素的积 乘 A[i] 右边所有元素的积
*/
#include <vector>
#include <stdio.h>

std::vector<int> constructArr(std::vector<int>& a) 
{
    int n = a.size();
    std::vector<int> ret(n, 1);
    int left = 1;
    for (int i = 0; i < n; i++)
    {
        ret[i] = left;
        left = left * a[i];
        printf("%d\n", ret[i]);
    } 
    int right = 1;
    for (int i = n-1; i >= 0; i--) 
    {
        ret[i] *= right;
        right *= a[i];
        printf("%d\n", ret[i]);
    }
    return ret;
}

int main(int argc, char** argv)
{
    std::vector<int> a = {1,2,3,4,5};
    constructArr(a);
}