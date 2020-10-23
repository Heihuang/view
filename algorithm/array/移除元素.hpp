/*
题目：给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素
解法：
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;//慢指针
        for(int j=0//快指针;j<nums.size();j++)
        {
            if(nums[j]!=val)//寻找不需要剔除的元素
            {
                nums[i]=nums[j];
                i++;
            }
        }
        return i;
    }
};

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int i=0;
        while(i<n)
        {
            if(nums[i]==val)
            {
                nums[i]=nums[n-1];
                n--;
            }
            else i++;
        }
        return n;
    }
};
