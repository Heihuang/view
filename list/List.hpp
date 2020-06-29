#include <iostream>

namespace view
{
//定义Node节点
struct ListNode
{
    /* data */
    int value_;
    ListNode* next_;
};

//面试题1：在链表末尾添加一个节点
void AddToTail(ListNode** head, int value)
{
    //创建新节点，让新节点next指向null，作为尾节点
    ListNode* new_node = new ListNode();
    new_node->value_ = value;
    new_node->next_ = nullptr;
    //如果链表为空
    if (*head == nullptr)
    {
        *head = new_node;
    }
    else
    {
        /* code */
        //找到最后一个节点，让最后一个节点next指向新节点
        ListNode *node = *head;
        while (node->next_ != nullptr)
        {
            node = node->next_;
        }
        node->next_ = new_node;
    }
    
}
//面试题2：找到第一个含有某值的节点并删除
void RemoveNode(ListNode** head, int value)
{
    if (head == nullptr || *head == nullptr)
    {
        return;
    }
    //如果要删除的节点是头节点，则替换头节点
    ListNode* tobedel = nullptr;
    if ((*head)->value_ == value)
    {
        /* code */
        tobedel = *head;
        *head = (*head)->next_;

    }
    else
    {
        /* code */
        ListNode* node = *head;
        while (node->next_ != nullptr && node->next_->value_ != value)
        {
            /* code */
            node = node->next_;
            if (node->next_ != nullptr && node->next_->value_ == value)
            {
                tobedel = node->next_;
                node->next_ = node->next_->next_;
            }
        }
        if (tobedel != nullptr)
        {
            delete tobedel;
            tobedel = nullptr;
        }
    }
    
    
}

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
//思路2：递归，每访问一个节点的时候，先递归输出后面的节点，再输出该节点自身
void PrintListReversingly_Recursively(ListNode *head)
{
    if (head != nullptr)
    {
        if (head->next_ != nullptr)
        {
            PrintListReversingly_Recursively(head->next_);
        }
        std::cout << head->value_ << std::endl;
    }
    
}

}