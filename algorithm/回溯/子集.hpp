/*
题目：给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。说明：解集不能包含重复的子集
解法：
*/
class Solution {
public:
    void backtrack(vector<int> nums, vector<vector<int>> &res, vector<int>& path, int start){
        res.push_back(path);
        for(int i = start; i < nums.size(); i++){
            path.push_back(nums[i]);
            backtrack(nums, res, path, i+1);
            path.pop_back();
            while(i < nums.size()-1 && nums[i] == nums[i+1]){
                i++;
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res; 
        vector<int> path;
        backtrack(nums, res, path, 0);
        return res;
    }
};