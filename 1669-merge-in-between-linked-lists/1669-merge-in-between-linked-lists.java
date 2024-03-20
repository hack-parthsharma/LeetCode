class Solution {
public ListNode mergeInBetween(
            ListNode list1, int a, int b, ListNode list2) {
        ListNode current = list1;
for (int i = 1; i < a; i++) {
            current = current.next;
}
        ListNode toRemove = current.next;
        current.next = list2;
for (int i = 0; i < b - a + 1; i++) {
            toRemove = toRemove.next;
}
        ListNode lastNode = lastNode(list2);
        lastNode.next = toRemove;
        return list1;
}
    
    ListNode lastNode(ListNode node) {
        ListNode current = node;
while(current.next != null) {
            current = current.next;
        }
return current;
}
}