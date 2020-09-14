/*
题目：一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。
在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字
解法：如果 k == nums[k]，那么缺失的数字一定在 k 右边，如果 k != nums[k]，那么缺失的数字要么为 k 要么在 k 左边；
这个很类似于二分查找，我们也可以使用二分的思想去优化时间复杂度。
*/
#include <vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    int left = 0, right = nums.size();
    while(left < right){
        int mid = (left + right)/2;
        if(mid == nums[mid]) left = mid + 1;
        else right = mid;
    }
    return left;
}
