/*
题目：给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
注意:
不能使用代码库中的排序函数来解决这道题。
解法：
循环不变量定义 1
循环不变量：声明的变量在遍历的过程中需要保持定义不变。
设计循环不变量的原则
说明：设计循环不变量的原则是 不重不漏。
len 是数组的长度；
变量 zero 是前两个子区间的分界点，一个是闭区间，另一个就必须是开区间；
变量 i 是循环变量，一般设置为开区间，表示 i 之前的元素是遍历过的；
two 是另一个分界线，我设计成闭区间。
如果循环不变量定义如下：

所有在子区间 [0, zero) 的元素都等于 0；
所有在子区间 [zero, i) 的元素都等于 1；
所有在子区间 [two, len - 1] 的元素都等于 2。
于是编码要解决以下三个问题：
变量初始化应该如何定义；
在遍历的时候，是先加减还是先交换；
什么时候循环终止。
处理这三个问题，完全看循环不变量的定义。
编码的时候，zero 和 two 初始化的值就应该保证上面的三个子区间全为空；
在遍历的过程中，「下标先加减再交换」、还是「先交换再加减」就看初始化的时候变量在哪里；
退出循环的条件也看上面定义的循环不变量，在 i == two 成立的时候，上面的三个子区间就正好 不重不漏 地覆盖了整个数组，并且给出的性质成立，题目的任务也就完成了。
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int size = nums.size();
        if (size < 2) {
            return;
        }

        // all in [0, zero) = 0
        // all in [zero, i) = 1
        // all in [two, len - 1] = 2

        int zero = 0;
        int two = size;
        int i = 0;
        while (i < two) {
            if (nums[i] == 0) {
                swap(nums[zero], nums[i]);
                zero++;
                i++;
            } else if (nums[i] == 1) {
                i++;
            } else {
                two--;
                swap(nums[i], nums[two]);
            }
        }
    }
};
