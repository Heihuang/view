/*
题目：输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。
如果有多对数字的和等于s，则输出任意一对即可。
解法：从第一个和最后一个元素开始算。
如果算出来的结果比目标大，那就最后一个往前移，否则就第一个目标往后移
*/

#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {  // 双指针
    vector<int> result;
    int sum, i = 0, j = nums.size()-1;
    while(i < j){
        sum = nums[i]+nums[j];
        if(sum==target){
            result.push_back(nums[i]);
            result.push_back(nums[j]);
            break;
        }
        if(sum>target) j--;
        else i++;
    }
    
    return result;
}

