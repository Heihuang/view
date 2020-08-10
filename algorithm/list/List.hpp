#include "../head.h"
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
                break;
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
//面试题4:在O(1)时间删除链表节点
//核心思路：设置pre、curr两个指针，两个指针同时向前移动，
//判断curr指向节点的内容是否等于val
ListNode* deleteNode(ListNode* head, int val) 
{
    ListNode*pre=head; //指向前一个节点
    ListNode*curr=head->next_; //指向后一个节点
    if(head->value_==val)return curr;
    while(curr!=nullptr)
    {
        //当curr的值为要删除的时，让pre的next指向curr的next
        if(curr->value_==val)
        {
            pre->next_=curr->next_;
            //释放curr
            //delete curr;
            //curr = nullptr;
            return head;
        }
        else
        {
            //同时向后移动
            curr=curr->next_;
            pre=pre->next_;
        }
    }
    return head;
}
//面试题5:链表中的倒数第k个节点
/************************************
定义2个指针，quick，slow
先让quick往后跑k次
quick 和 slow一起跑，直到quick跑到结尾
slow位置，即为倒数第k个数
**************************************/
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


//面试题6:反转链表
/********************************
 头插法，不断的将next交互到链表头部
 *******************************/
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
        //将p指向head->next->next
        p = head->next_;
    }
    return q;
}

/***递归法**/
ListNode* reverseList(ListNode* head) 
{
    if(!head || !head->next_)
        return head;
    // p一直是最后一个非空节点
    ListNode* p = reverseList(head->next_);
    head->next_->next_ = head;
    head->next_ = nullptr;
    return p;
}

//面试题7:合并两个有序链表
//定义头结点
//若l1指向的结点值 < l2 指向的结点值，则将l1链接到头结点的next位置
//否则将l2链接到头结点的next位置
//循环进行，直至l1或l2为NULL
//最后，将l1或l2中剩下的部分，链接到头结点后面
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode();
    ListNode* ret = head;
    while (l1 != NULL && l2 != NULL) {
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
    head->next_ = l1 == NULL ? l2 : l1;
    return ret->next_;
}

//面试题8:两个链表的第一个公共节点
//面试题9:圆圈中最后剩下的数字
//面试题10:复杂链表的复制
//面试题11:二叉搜索树与双向链表
}