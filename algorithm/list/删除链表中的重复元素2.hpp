/*
题目：给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字
解法：三指针法
使用while循环去找这一段相同的值：如果循环结束的时候，L与R是同一节点，说明，没有重复节点
如果循环结束，L不等于R，则L到R这一段都是重复的，则需要将当前节点PCUR的next指向R的下一的指针，同时L也是
指向R，重复刚才循环动作
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
   ListNode* deleteDuplicates(ListNode* head) {
        ListNode* PCUR=new ListNode(0);
        PCUR->next=head;
        head=PCUR;
        ListNode *L,*R;
        while(PCUR->next != NULL)
        {
            L=PCUR->next;
            R=PCUR->next;
            while(R->next && R->next->val==L->val)
                R=R->next;
            //如果循环后，L与R节点相同，说明不重复
            if(L == R) PCUR=PCUR->next;
            //L与R节点不相同，将PCUR的next指向R->next,继续重复上述操作
            else 
            {
                PCUR->next=R->next;
                //C++没有内存回收机制，应该释放这些指针，虽然不释放能通过，但是应该养成好习惯
                while(L!=R)
                {
                    ListNode*tmp=L;
                    L=L->next;
                    delete tmp;
                }
                delete L;
            }
        }
        return head->next;
    }
};