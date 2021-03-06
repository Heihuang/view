/*
当n很大的时候可能会出现数字溢出，所以我们需要用结果对1000000007求余，
但实际上可能还没有执行到最后一步就已经溢出了，所以我们需要对每一步的计算都要对1000000007求余
是1e9+7吧，因为这是一个很大的质数，而且刚好相加不会爆int，相乘不会爆long long
*/
int fib(int n) {
    if(n <= 1) 
        return n;
    int f2 = 0, f1 = 1;
    int res;
    for(int i = 2; i <=n; i++){
        res = (f2 + f1) % 1000000007;
        f2 = f1; 
        f1 = res;
    }
    return res;
}
