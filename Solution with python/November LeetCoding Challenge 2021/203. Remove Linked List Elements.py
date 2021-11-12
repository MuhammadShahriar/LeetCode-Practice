# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        ans = ListNode()
        ret = ans
        ok = 0
        while ( head ) :
            if ( head.val != val ) :
                ok = 1
                ans.val = head.val
                done = 0
                
                cur = head.next
                while (cur) :
                    if ( cur.val != val ) :
                        done = 1
                        break
                    cur = cur.next
                    
                
                    
                if (done == 0) :
                    ans.next = None
                else:
                    ans.next = ListNode()
                ans = ans.next;
                
            head = head.next
            
        if ( ok == 0 ):
            return None;
        return ret