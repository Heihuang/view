/*
题目：输入一个链表，输出该链表中倒数第k个节点
解法：定义2个指针，quick，slow
先让quick往后跑k次
quick 和 slow一起跑，直到quick跑到结尾
slow位置，即为倒数第k个数
*/

ListNode* getKthFromEnd(ListNode* head, int k) 
{
    if(head == nullptr)
        return head;
    ListNode* quick = head;
    ListNode* slow = head;
    //先移动快指针k步
    while(k-- && quick)
    {
        quick = quick->next_;
    }
    //k大于链表长度
    if(quick == nullptr)
       return head;
    //quick跑到结尾,slow位置，即为倒数第k个数
    while(quick)
    {
        quick = quick->next_;
        slow = slow->next_;
    }
    return slow;
}