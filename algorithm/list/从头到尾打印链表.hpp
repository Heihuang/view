#include <stack>
#include <iostream>
//定义Node节点
struct ListNode
{
    /* data */
    int value_;
    ListNode* next_;
    ListNode* random_;
};

//面试题3：从尾到头打印链表
//输入一个链表的头节点，从尾到头反过来打印每个节点。
//思路1：栈，先进后出，stl stack
void PrintListReversingly_Iteratively(ListNode *head)
{
    std::stack<ListNode*> nodes;
    ListNode *node = head;
    while (node != nullptr)
    {
        /* code */
        //入栈
        nodes.push(node);
        node = node->next_;
    }
    while (!nodes.empty())
    {
        /* code */
        node = nodes.top();
        std::cout << node->value_ << std::endl;
        nodes.pop();
    }
}
