class Solution:
    def insertionSortList(self, head):
        dummy = ListNode(0)
        curr = head
        
        while curr:
            prev = dummy
            while prev.next and prev.next.val < curr.val:
                prev = prev.next
                
            next_temp = curr.next
            curr.next = prev.next
            prev.next = curr
            curr = next_temp
            
        return dummy.next