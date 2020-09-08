/*
题目：数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，
第13位是1，第19位是4，等等。
请写一个函数，求任意第n位对应的数字
解法：对于第 n 位对应的数字，我们令这个数字对应的数为 target，然后分三步进行。
首先找到这个数字对应的数是几位数，用 digits 表示；
然后确定这个对应的数的数值 target；
最后确定返回值是 target 中的哪个数字。
*/
int findNthDigit(int n) {
    // 计算该数字由几位数字组成，由1位：digits = 1；2位：digits = 2...
    long base = 9,digits = 1;
    while (n - base * digits > 0){
        n -= base * digits;
        base *= 10;
        digits ++;
    }

    // 计算真实代表的数字是多少
    int idx = n % digits;  // 注意由于上面的计算，n现在表示digits位数的第n个数字
    if (idx == 0)idx = digits;
    long number = 1;
    for (int i = 1;i < digits;i++)
        number *= 10;
    number += (idx == digits)? n/digits - 1:n/digits;

    // 从真实的数字中找到我们想要的那个数字
    for (int i=idx;i<digits;i++) number /= 10;
    return number % 10;
}
