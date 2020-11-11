/*
题目：给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次
解法：
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* p=head;//慢指针
        ListNode* q=head->next;//快指针
        while(p->next!=NULL)
        {
            if(p->val==q->val)//找到重复元素
            {
                if(q->next==NULL)//快指针后面若没有元素直接剔除
                    p->next=NULL;
                else//快指针后有元素
                {
                    p->next=q->next;
                    q=q->next;
                }
            }
            else //元素不相等
            {
                p=p->next;
                q=q->next;
            }
        }
        return head;
    }
};
