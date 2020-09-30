/*
题目：给定一个链表，返回链表开始入环的第一个节点。如果链表无环，则返回 null。
为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环
解法：
*/
ListNode* detectCycle(ListNode* head) {
	ListNode* fastPtr=head, *slowPtr=head;
	// 让fast与slow指针第一次相遇
	while (fastPtr!=NULL && fastPtr->next!=NULL)
	{
		fastPtr = fastPtr->next->next;
		slowPtr = slowPtr->next;
		if (fastPtr==slowPtr)
		{
			// 从相遇点再走“非环部分长度”一定可以再次走到环起点
			fastPtr = head;
			while (fastPtr != slowPtr)
			{
				fastPtr = fastPtr->next;
				slowPtr = slowPtr->next;
			}
			return fastPtr;
			break;
		}
	}

	return nullptr;
}

