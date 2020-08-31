/*
题目描述：实现函数double Power(double base, int exponent)，求base的exponent次方。
不得使用库函数，同时不需要考虑大数问题。
解法：快速幂解析（二进制角度）
对于任何十进制正整数n，

*/

double myPow(double x, int n) 
{
    if(x == 1 || n == 0) return 1;
    double ans = 1;
    long num = n;
    if(n < 0){
        num = -num;
        x = 1/x;
    }
    while(num){
        if(num & 1) ans *= x;
        x *= x;
        num >>= 1;
    }
    return ans;
}
