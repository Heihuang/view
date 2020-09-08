/*
题目：输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数
解法：
我们假设高位为high，当前位为cur，低位为low，i代表着需要统计的位置数（1对应个位，10对应十位，100对应百位），
则对每一位的个数count有：
cur=0,count = high*i;
cur=1,count=high*i+low+1;
cur>1,count=high*i+i
最终累加所有位置上的个数即最终答案
*/
int countDigitOne(int n) {
    int count = 0;
    long i = 1;//指向遍历的位数，如i=1即个位，i=10即十位，...，因为n可以有31位，所以10^31用long存储
    while(n/i!=0){
        //n/i控制遍历的次数，将所有的位数都遍历完毕
        long high = n/(10*i);//将当前位之前的所有高位都存在high中
        long cur = (n/i)%10;//将当前位记录在cur中，即我们每次都需要统计当前位上1出现的次数
        long low = n-(n/i)*i;
        if(cur == 0){
            count += high * i;
        } else if(cur == 1){
            count += high * i + low + 1;
        } else {
            count += high * i + i;
        }
        i = i * 10;//准备遍历下一位
    }
    return count;
}
