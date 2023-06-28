class Solution {
 public:
  ListNode* deleteMiddle(ListNode* head) {
    ListNode dummy(0, head);
    ListNode* slow = &dummy;
    ListNode* fast = &dummy;

    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    slow->next = slow->next->next;
    return dummy.next;
  }
};
