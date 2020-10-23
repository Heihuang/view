/*
题目：给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
解法L：
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0; // 别忘记空数组的判断
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < (nums.size() - 1); fastIndex++){
            if(nums[fastIndex] != nums[fastIndex + 1]) { // 发现和后一个不相同
                nums[++slowIndex] = nums[fastIndex + 1]; //slowIndex = 0 的数据一定是不重复的，所以直接 ++slowIndex
            }
        }
        return slowIndex + 1; //别忘了slowIndex是从0开始的，所以返回slowIndex + 1
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       return unique(nums.begin(), nums.end()) - nums.begin();
    }
};