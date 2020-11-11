/*
题目：格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。
给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。即使有多个不同答案，你也只需要返回其中一种。
格雷编码序列必须以 0 开头
解法：
n = 0, [0]
n = 1, [0,1] //新的元素1，为0+2^0
n = 2, [0,1,3,2] // 新的元素[3,2]为[0,1]->[1,0]后分别加上2^1
n = 3, [0,1,3,2,6,7,5,4] // 新的元素[6,7,5,4]为[0,1,3,2]->[2,3,1,0]后分别加上2^2->[6,7,5,4]
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        int shift = 1;
        vector<int> res;
        while(n >= 0){
            if(res.size() == 0){
                res.push_back(0);
            }else{
                for(int i = shift-1; i >= 0; --i){
                    res.push_back(res[i] + shift);
                }
                shift *= 2;
            }
            --n;
        }
        return res;
    }
};
