/*
题目：给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转
解法：弹出和推入数字 & 溢出前进行检查
如果temp=rev*10+pop导致溢出，那么一定有rev>=INT_MAX/10
如果rev>INT_MAX/10,那么temp=rev*10+pop一定会溢出
如果rev==INT_MAX/10,那么只要pop>7,temp=rev*10+pop就会溢出
*/
int reverse(int x) {
    int rev = 0;
    while (x != 0) {
        int pop = x % 10;
        x /= 10;
        if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
        if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
        rev = rev * 10 + pop;
    }
    return rev;
}
