/*
题目：定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点
解法：头插法
*/
ListNode* reverseList(ListNode* head) 
{
    //链表为空或只有一个节点 返回head
    if(!head || !head->next_)
        return head;
    ListNode* p = head->next_, *q = head;
    while(p)
    {
        //head next先后移动
        head->next_ = p->next_;
        //将head插入到next位置
        p->next_ = q;
        //将next插入到头
        q = p;
        //将p指向head->next
        p = head->next_;
    }
    return q;
}

ListNode* reverseList(ListNode* head) {
    if(!head || !head -> next) return head;
    // 把 1 分离出来，然后假设后面的 2345NULL 都已经反转好了(即 NULL<-2<-3<-4<-5)，让它们是curr
    ListNode *curr = reverseList(head -> next);
    // 这时候开始处理1，把1接上curr就完成任务了。此时head是1，curr是 NULL<-2<-3<-4<-5。此时 head->next仍然是2，则：
    // head->next->next是NULL。所以写了这一行之后，就会变成 1<-2<-3<-4<-5
    head -> next -> next = head;
    // 这一行就是把 NULL接在 1 的后面，变成 NULL<-1<-2<-3<-4<-5
    head -> next = nullptr;
    return curr;
}

