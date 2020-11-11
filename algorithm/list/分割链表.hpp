/*
题目：给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
你应当保留两个分区中每个节点的初始相对位置
解法：相当于先将链表拆分成两部分，然后再将和两部分拼接起来
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *h1 = new ListNode(-1); // 记录比x小的节点组成的链表
        ListNode *h2 = new ListNode(-1); // 记录比x大的节点组成的链表
        ListNode *p1 = h1, *p2 = h2;
        while (head) {
            if (head -> val < x) {
                p1 -> next = head;
                p1 = p1 -> next;
            } else {
                p2 -> next = head;
                p2 = p2 -> next;
            }
            head = head -> next;
        }
        // 将两个链表拼接起来
        p2 -> next = nullptr;
        p1 -> next = h2 -> next;
        return h1 -> next;
    }
};