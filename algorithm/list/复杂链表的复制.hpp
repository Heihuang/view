/*
题目：请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，
还有一个 random 指针指向链表中的任意节点或者 null。
*/
//方法一：利用哈希表map，深度拷贝源节点，再拷贝随机节点
ListNode* copyRandomList(ListNode* head)
{
    if(head == nullptr)
        return nullptr;
            
    //创建map对象，并将深度复制的节点添加到map中
    std::unordered_map<ListNode*,ListNode*> newHead;
    ListNode *pNode = head;
    while(pNode != nullptr)
    {
        newHead[pNode] = new ListNode();//添加键值对
        pNode = pNode->next_;
    }
    //添加next/random指针
    pNode = head;
    while(pNode != nullptr)
    {
        newHead[pNode]->next_ = newHead[pNode->next_];
        newHead[pNode]->random_ = newHead[pNode->random_];
        pNode = pNode->next_;
    }
    return newHead[head];
}
//方法二：
ListNode* copyRandomListEx(ListNode* head)
{
    if(head == nullptr)
        return nullptr;
    ListNode *pNode = head;
    while(pNode != nullptr)
    {
        ListNode *pNext = pNode->next_;
        //创建新节点
        ListNode *newNode = new ListNode();
        //newNode->val = pNode->val;
        //插入新节点
        pNode->next_ = newNode;
        newNode->next_ = pNext;
        pNode = pNext;
    }

    //复制随机指针
    ListNode *preNode = head;
    while(preNode != nullptr)
    {
        pNode = preNode->next_;
        //添加随即指针
        pNode->random_ = preNode->random_ == nullptr ? nullptr : preNode->random_->next_;
        //更新当前处理的节点
        preNode = pNode->next_;
    }

    //拆分成两个链表
    preNode = head;
    ListNode *newHead = preNode->next_;
    while(preNode != nullptr)
    {
        pNode = preNode->next_;
        preNode->next_ = pNode->next_;
        preNode = preNode->next_;
        pNode->next_ =  preNode == nullptr ? nullptr : preNode->next_;
    }
    return newHead;
}