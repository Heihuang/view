/*
题目：缺失的正数
解法：
我们将数组中所有小于等于0的修改为N+1
遍历数组中的每一个数x，它可能已经被打了标记，因此原本对应的数为|x|,其中||为绝对值符号，如果|x|属于[1, N],那么我们给数组中的
第|x|-1个位置的数添加一个负号。注意如果它已经有负号，不需要重复添加；
在遍历完成之后，如果数组中的每一个数都是负数，那么答案是N+1，否则答案是第一个正数的位置加1

*/·
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int& num: nums) {
            if (num <= 0) {
                num = n + 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            int num = abs(nums[i]);
            if (num <= n) {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
