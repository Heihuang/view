/*
题目：数组中重复的数字
描述：在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
请找出数组中任意一个重复的数字。
思路：用hashset，如果count不等于1，则说明数字存在
*/
#include <vector>
#include <unordered_set>
using namespace  std;

int findRepeatNumber(vector<int>& nums) 
{
    unordered_set<int> nSet;
    for(int i : nums)
    {
        // 假如hashset中已经有i了，说明重复了，返回i
        if(nSet.count(i) != 0) return i; 
        else nSet.insert(i);
    }
    return -1;
       
}