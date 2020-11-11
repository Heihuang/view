/*
题目：给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵
*/
vector<vector<int>> generateMatrix(int n) { 
    vector<vector<int>> res(n, vector<int>(n)); 
    //s,e表示每圈矩阵的开始索引和结束索引，m表示填充的值，循环的结束条件是s>e
    for(int s = 0, e = n - 1, m = 1; s<=e ; s++,e--){
        //从左到右横向 
        for (int j = s; j <= e; j++) res[s][j] = m++;
        //从上到下纵向，注意：i 从s+1开始
        for (int i = s+1; i <= e; i++) res[i][e] = m++;
        //从右到左横向，注意：j 从e-1开始
        for (int j = e-1; j >= s; j--) res[e][j] = m++;
        //从下到上纵向，注意：i 从e-1开始，到s+1结束 !!
        for (int i = e-1; i >= s+1; i--) res[i][s] = m++;
    }
    return res;
}
