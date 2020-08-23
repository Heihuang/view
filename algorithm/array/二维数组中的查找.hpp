/*
题目描述：在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，
判断数组中是否含有该整数
解法：每一行都是递增的，每一列都是递增的
首先，我们初始化一个指向矩阵右上角的 元素 。
从这个元素开始查找，如果这个元素比 target 大，则说明需要找更小的，往左走；
如果这个元素比 target 小，则说明应该找更大的，往下走

*/

#include <vector>
using namespace std;

bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) 
{
    int i = matrix.size() - 1, j = 0;
    while(i >= 0 && j < matrix[0].size())
    {
        if(matrix[i][j] > target) i--;
        else if(matrix[i][j] < target) j++;
        else return true;
    }
    return false;
}