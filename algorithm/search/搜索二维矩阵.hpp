/*
题目：
解法：
初始化左右序号：left=0和right=m*n-1
while left < right
    选取数组最中间的序号作为中间序号:pivot_idx=（left+right）/2
    该序号对应于原矩阵中的 row = pivot_idx / n  col = pivot_idx % n,由此可以
    拿到中间元素pivot_element.
    比较pivot_element于target，确定在那部分查找
*/
class Solution {
  public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();

    // 二分查找
    int left = 0, right = m * n - 1;
    int pivotIdx, pivotElement;
    while (left <= right) {
      pivotIdx = (left + right) / 2;
      pivotElement = matrix[pivotIdx / n][pivotIdx % n];
      if (target == pivotElement) return true;
      else {
        if (target < pivotElement) right = pivotIdx - 1;
        else left = pivotIdx + 1;
      }
    }
    return false;
  }
};
