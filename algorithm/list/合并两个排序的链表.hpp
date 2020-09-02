//定义头结点
//若l1指向的结点值 < l2 指向的结点值，则将l1链接到头结点的next位置
//否则将l2链接到头结点的next位置
//循环进行，直至l1或l2为NULL
//最后，将l1或l2中剩下的部分，链接到头结点后面
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
    ListNode* head = new ListNode();
    ListNode* ret = head;
    while (l1 != nullptr && l2 != nullptr) {
        //若l1指向的结点值 < l2 指向的结点值，则将l1链接到头结点的next位置
        if (l1->value_ < l2->value_) {
            head->next_ = l1;
            l1 = l1->next_;
        } else {
            //否则将l2链接到头结点的next位置
            head->next_ = l2;
            l2 = l2->next_;
        }
        head = head->next_;
    }
    //将l1或l2中剩下的部分，链接到头结点后面
    head->next_ = l1 == nullptr ? l2 : l1;
    return ret->next_;
}