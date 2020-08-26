/*
题目：一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
解法：斐波那契
*/

int numWays(int n) 
{
    if(n == 0 || n == 1) return 1;
    int N = 0, NMinusOne = 1, NMinusTwo = 1;
    while(n >= 2)
    {
        // 采取从下往上的方法，把计算过的中间项保存起来，避免重复计算导致递归调用栈溢出
        N = (NMinusOne + NMinusTwo) % 1000000007;
        NMinusTwo = NMinusOne;
        NMinusOne = N;
        n --;
    }
    return N;
}

