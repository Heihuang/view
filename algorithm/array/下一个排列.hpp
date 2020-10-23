/*
*题目：实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）
*/

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int pos = nums.size() - 1;
		while (pos > 0 && nums[pos] <= nums[pos - 1])
			pos--;
		reverse(nums.begin() + pos, nums.end());  //逆序
		if(pos > 0){
			auto iter = upper_bound(nums.begin() + pos, nums.end(), nums[pos - 1]);//使用upper_bound找到遍历过的数中第一个比num[pos-1]大的数
			swap(*iter, nums[pos - 1]);
		}
	}
};
