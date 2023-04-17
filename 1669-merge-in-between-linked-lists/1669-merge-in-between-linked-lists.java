class Solution {
    public ListNode mergeInBetween(
            ListNode list1, int a, int b, ListNode list2) {
        // 1. Go to the node that will be dereferenced
        ListNode current = list1;
        for (int i = 1; i < a; i++) {
            current = current.next;
        }
        // 2. Remove the first node to remove
        ListNode toRemove = current.next;
        // 3. De-reference to list2
        current.next = list2;
        // 4. Find the first node to add at the end of list 2
        for (int i = 0; i < b - a + 1; i++) {
            toRemove = toRemove.next;
        }
        // 5. Find the last node in list 2
        ListNode lastNode = lastNode(list2);
        // 6. De-reference last node to the end of list 1
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