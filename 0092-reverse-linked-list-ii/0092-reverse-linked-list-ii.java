/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        if (head == null || left == right) {
            return head;
        }

        // Create a dummy node to handle edge cases where left = 1
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prev = dummy;

        // 1. Move 'prev' to the node just before the 'left' position
        for (int i = 0; i < left - 1; i++) {
            prev = prev.next;
        }

        // 2. 'current' points to the first node of the sublist to be reversed
        ListNode current = prev.next;
        ListNode nextNode = null;
        ListNode sublistTail = current;

        // 3. Reverse the sublist from 'left' to 'right' in one pass
        ListNode prevSub = null;
        for (int i = 0; i <= right - left; i++) {
            nextNode = current.next;
            current.next = prevSub;
            prevSub = current;
            current = nextNode;
        }

        // 4. Connect the reversed sublist back to the original list
        prev.next = prevSub;
        sublistTail.next = current;

        return dummy.next;
    }
}