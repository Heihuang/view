/*
题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分
*/
#include <vector>
using namespace std;

vector<int> exchange(vector<int>& nums) 
{
    vector<int> res(nums.size());
    int i = 0, j = nums.size() - 1;
    for(int n : nums) 
        if(n % 2 == 1) res[i ++] = n;
        else res[j --] = n;
    return res;
}

