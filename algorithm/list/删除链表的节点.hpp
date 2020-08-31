/*
题目：给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。返回删除后的链表的头节点
解法一：递归法
思路：遍历链表，在节点head处考虑。
当head.val == val时，要删除head节点，那么，返回节点后面的链表头head->next。
当head.val ！= val时，要在head节点之后的部分继续删除。递归执行删除算法。
注意删除后，剩余的链表要再次拼接到head的后面。
解法2:单指针扫描法
思路：遍历链表，开始在p=head处考虑。
当p->val == val时，删除p，返回p后面的链表头节点。
当p->next->val ！= val时，向后遍历，直到p->next->val == val时止。删除p->next即可。
*/
ListNode* deleteNode1(ListNode* head, int val) 
{
    if(!head) return head;
    if(head->val == val) return head->next;
    //递归删除
    head->next = deleteNode(head->next,val);
    return head;
}

ListNode* deleteNode2(ListNode* head, int val) 
{
    if(!head) return head;
    if(head->val == val) return head->next;
    ListNode* p=head;
    while(p->next && p->next->val != val){
        p=p->next;
    }
    if(p->next && p->next->val == val)  p->next = p->next->next;
    return head;
}
