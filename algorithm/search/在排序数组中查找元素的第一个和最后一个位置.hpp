/*
题目：给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
你的算法时间复杂度必须是 O(log n) 级别。
如果数组中不存在目标值，返回 [-1, -1]
解法：二分法左右逼近
划分[left, mid]与[mid+1, right],mid被分到左边，对应int mid = left + (right - left) / 2;
划分[left, mid - 1]与[mid, right],mid被分到右边，对应int mid=left + (right -left + 1)/2
*/
#include <iostream>
#include <vector>

using namespace std;


class Solution {
private:
    int findFitstPosition(vector<int> &nums, int target) {
        int size = nums.size();
        int left = 0;
        int right = size - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] == target){
                right = mid;
            } else {
                // nums[mid] > target
                right = mid - 1;
            }
        }
        if (nums[left] != target) {
            return -1;
        }
        return left;
    }

    int findLastPosition(vector<int> &nums, int target) {
        int size = nums.size();
        int left = 0;
        int right = size - 1;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] == target){
                left = mid;
            } else {
                // nums[mid] < target
                left = mid + 1;
            }
        }
        if (nums[left] != target) {
            return -1;
        }
        return left;
    }


public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int size = nums.size();
        if (size == 0) {
            return {-1, -1};
        }
        int fitstPosition = findFitstPosition(nums, target);

        if (fitstPosition == -1) {
            return {-1, -1};
        }
        int lastPosition = findLastPosition(nums, target);
        return {fitstPosition, lastPosition};
    }
};
