/*
题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，
输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  
解法：数组中的最后一个元素 x：在最小值右侧的元素，它们的值一定都小于等于x；而在最小值左侧的元素，它们的值一定都大于等于x。
因此，我们可以根据这一条性质，通过二分查找的方法找出最小值。
在二分查找的每一步中，左边界为low，右边界为high，区间的中点为pivot，最小值就在该区间内。我们将中轴元素numbers[pivot] 
与右边界元素numbers[high] 进行比较，可能会有以下的三种情况
第一种情况是numbers[pivot]<numbers[high]。这说明numbers[pivot] 是最小值右侧的元素，
因此我们可以忽略二分查找区间的右半部分。
第二种情况是numbers[pivot]>numbers[high]。这说明numbers[pivot]是最小值左侧的元素，
因此我们可以忽略二分查找区间的左半部分
第三种情况是 
numbers[pivot]==numbers[high]。由于重复元素的存在，我们并不能确定 
numbers[pivot] 究竟在最小值的左侧还是右侧，因此我们不能莽撞地忽略某一部分的元素。
我们唯一可以知道的是，由于它们的值相同，所以无论numbers[high] 是不是最小值，都有一个它的「替代品」
numbers[pivot]，因此我们可以忽略二分查找区间的右端点。
*/
#include <vector>
using namespace std;

int minArray(vector<int>& numbers) {
    int low = 0;
    int high = numbers.size() - 1;
    while (low < high) {
        int pivot = low + (high - low) / 2;
        if (numbers[pivot] < numbers[high]) {
            high = pivot;
        }
        else if (numbers[pivot] > numbers[high]) {
            low = pivot + 1;
        }
        else {
            high -= 1;
        }
    }
    return numbers[low];
}