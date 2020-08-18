//让循环继续的条件是colums>startX*2 && rows>startY*2
void PrintMatInCircle(int** nums, int cols, int rows, int start)
{
    int endX = cols - 1 - start;
    int endY = rows - 1 - start;
    //从左到右
    for (int i = start; i <= endX; i++)
    {
        int n = nums[start][i];
        //print(n);
    }
    //从上到下 (至少有两行)
    if (start < endY)
    {
        for (int i = start + 1; i <= endY; i++)
        {
            int n = nums[i][endX];
        }
    }
    //从右至左（至少两列两行）
    if (start < endY && start < endX)
    {
        for (int i = endX - 1; i >= start; i--)
        {
            int n = nums[endY][i];
        }
    }
    //从下之上
    if (start < endX && start < endY - 1)
    {
        /* code */
        for (int i = endY - 1; i >= start + 1; i--)
        {
            int n = nums[i][start];
        }
    }
}

void PrintLoopAarry(int** nums, int cols, int rows)
{
    if (nums == nullptr || cols <= 0 || rows <=0)
    {
        /* code */
        return;
    }
    int start = 0;
    while (cols > start*2 && rows > start*2)
    {
        /* code */
        PrintMatInCircle(nums, cols, rows, start);
        ++start;
    }
    
}