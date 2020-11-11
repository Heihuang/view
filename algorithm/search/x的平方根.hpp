/*
题目：
解法：
由于 x平方根的整数部分ans是满足k^2<=x的最大k值，因此我们可以对
k进行二分查找，从而得到答案。
二分查找的下界为0，上界可以粗略地设定为x。在二分查找的每一步中，我们只需要比较中间元素
mid 的平方与x的大小关系，并通过比较的结果调整上下界的范围。由于我们所有的运算都是整数运算，不会存在误差，因此在得到最终的答案 
ans 后，也就不需要再去尝试 ans+1 了处。
*/
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
