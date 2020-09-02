/*
题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。
例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。
解法：通过定义一个辅助栈，存储合理的入栈状态。
首先i遍历popped数组，j=0指针指向pushed第一个元素
1.i第一个遇到4，那么pushed中的1，2，3肯定已经被压入栈s中，所以有了while循环
2.while循环结束后，j指向pushed中的4，poped[i=0]=4,j++跳过pushed中的4指向5，第一次遍历结束
3.第二次遍历i遇到5，此时栈中只有[1,2,3]不满足if条件,所以这个元素只可能是pushed中j还没遍历到的
4.j此时指向pushed的5，i指向poped的5,则不操作（压入s又弹出s），j++跳过，这时j已经==pushed.size()，第二次遍历结束
5.第三次遍历开始，i指向popped中的3，和s.top()相同，故执行if条件，第4，5次遍历步骤相同
6.结束，栈空，返回true
*/
#include <vector>
#include <stack>
using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    if(pushed.size()!=popped.size()) return false;
    stack<int> s;
    int j=0;//pushed指针
    for(int i=0;i<popped.size();i++){//遍历poped
        if(!s.empty()&&popped[i]==s.top()){
            s.pop();
            continue;
        }
        while(j<pushed.size()&&pushed[j]!=popped[i]){
            s.push(pushed[j++]);
        }
        j++;//当pushed[j]==popped[i]，跳过压入又弹出的元素下标
    }
    return s.empty();
}

