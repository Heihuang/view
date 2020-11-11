/*
题目：两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。
给出两个整数 x 和 y，计算它们之间的汉明距离

解法：bitset<32>定义32位的位运算，然后用count记录1的数量
*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        return bitset<32> (x ^ y).count();
    }
};
