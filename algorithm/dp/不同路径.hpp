/*
题目：一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
问总共有多少条不同的路径？
解法：
从起点(x=0,y=0) 出发，下一步只能向右或者向下到达第二点，向右则为(x+1，y) 向下则为(x，y+1)，
一直到(x=m，y=n) 这个点则为结束点视为一条路径。
因此从起点到终点的所有路径总数则为2个 以第二个点到终点的路径数的总和。
可以递归求解如下

*/
static int a[101][101]={0};//记录已经计算过的路径，大大提高效率
class Solution{
	public:
		int uniquePaths(int m, int n){
			if(m <= 0 || n <= 0)
				return 0;
			else if(m == 1  || n == 1)
				return 1;
			else if(m == 2 && n == 2)
				return 2;
			else if((m == 3 && n == 2) || (m == 2 && n == 3))
				return 3;
			if(a[m][n] > 0)
				return a[m][n];
			a[m-1][n] =  uniquePaths(m-1,n);
			a[m][n-1] =  uniquePaths(m,n-1);
			a[m][n] = a[m-1][n]+a[m][n-1];
			return a[m][n];
		}
};