/*
题目：统计一个数字在排序数组中出现的次数
思路：排序数组 nums中的所有数字target形成一个窗口，
记窗口的 左 / 右边界 索引分别为left和right分别对应窗口左边/右边的首个元素
使用二分法分别找到 左边界left和右边界right，易得数字 target的数量为 right-left-1。
*/
 int search(vector<int>& nums, int target) {
    if(nums.size() == 0)
        return 0;
    int l = first(nums, target);
    if (l == -1)
        return 0;
    int r = last(nums, target);
    return r - l + 1;
}

int first(vector<int>& nums, int target){
    int l = 0;
    int r = nums.size() - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(nums[mid] == target)
            r = mid - 1;
        else if(nums[mid] > target)
            r = mid - 1;
        else  // nums[mid] < target
            l = mid + 1;
    }
    if(l >= nums.size() || nums[l] != target) // if(l == nums.size() || nums[r + 1] != target)
        return -1;
    return l;
}

int last(vector<int>& nums, int target){
    int l = 0;
    int r = nums.size() - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(nums[mid] == target)
            l = mid + 1;
        else if(nums[mid] < target)
            l = mid + 1;
        else // nums[mid] > target
            r = mid - 1;
    }
    if(r < 0 || nums[l - 1] != target) // if(r == -1 || nums[r] != target)
        return -1;
    return r;
}
