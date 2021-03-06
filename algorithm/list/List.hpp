#include "../head.h"
namespace view
{
//定义Node节点
struct ListNode
{
    /* data */
    int value_;
    ListNode* next_;
    ListNode* random_;
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

//面试题8:两个链表的第一个公共节点
//我们使用两个指针 node1，node2 分别指向两个链表 headA，headB 的头结点，
//然后同时分别逐结点遍历，当 node1 到达链表 headA 的末尾时，
//重新定位到链表 headB 的头结点；当 node2 到达链表 headB 的末尾时，
//重新定位到链表 headA 的头结点。
//这样，当它们相遇时，所指向的结点就是第一个公共结点
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
    ListNode *node1 = headA;
    ListNode *node2 = headB;
    while (node1 != node2) {
        node1 = node1 != NULL ? node1->next_ : headB;
        node2 = node2 != NULL ? node2->next_ : headA;
    }
    return node1;
}

//面试题9:圆圈中最后剩下的数字
//            0, n=1
//    f(n,m)=        
//           ((m%n)+f(n−1,m))%n, n > 1

int lastRemaining(int n, int m) {
    int result = 0;
    for (int i = 2; i <= n; ++i) {
        result = (result + m) % i;
    }
    return result;
}

//面试题10:复杂链表的复制
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

//面试题11:二叉搜索树与双向链表
//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。
//要求不能创建任何新的节点，只能调整树中节点指针的指向。

struct TreeNode
{
    TreeNode* left_;
    TreeNode* right_;
};
//方法：一、搜索二叉树的特点：
//（1）其左子树的结点均小于它，其右子树的结点均大于它；
//（2）其子树也是搜索二叉树；
//根据二叉树 特点（2） 可联想到使用递归；
//二、问题分解如下：
//设：有任意结点 r
//step 1 将r的左子树变为有序链表，要输出此有序链表的头尾结点 Lhead、LTail；
//step 2 将r的右子树变为有序链表，要输出此有序链表的头尾结点 Rhead、RTail；
//step 3 将r结点与左有序链表和右有序两边连接；即将Ltail结点与r->left连接；将r->right 与 Rhead与其连接；
//step 4 返回以r结点为根的树的头与尾 ：Lhead、RTail
//截止条件：r 为叶子结点

TreeNode* treeToDoublyList(TreeNode* root) 
{
    if (root == nullptr)
    {
        return nullptr;
    }
    TreeNode* head, *tail;
    listTree(root, head, tail);
    head->left_ = tail;
    tail->right_ = head;
    return head;
}

void listTree(TreeNode* r, TreeNode* &head, TreeNode* &tail)
{
    if (r == nullptr)
    {
        return;
    }
    TreeNode* lhead, *ltail,*rhead,*rtail;
    lhead = r;
    if (r->left_ != nullptr){
        listTree(r->left_, lhead, ltail);
        r->left_ = ltail;
        ltail->right_ = r;
    }
    rtail = r;
    if (r->right_ != nullptr)
    {
        listTree(r->right_, rhead, rtail);
        r->right_ = rhead;
        rhead->left_ = r;
    }
    head = lhead;
    tail = rtail;
}

}