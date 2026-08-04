lass Solution {
    public ListNode swapNodes(ListNode head, int k) {
        ListNode first = head;
        ListNode second = head;
        ListNode second1 = head;
        ListNode second2 = head;
        ListNode second3 = head;
        int count = 0;
        
       
        while (second3 != null) {
            count++;
            second3 = second3.next; 
        }

       
        for (int i = 0; i < k - 1; i++) {
            second1 = second1.next;
        }
        first = second1;
        int l = count - k;
        for (int j = 0; j < l; j++) { 
            second2 = second2.next;          
        }
        second = second2;
        
        
        int temp = first.val;
        first.val = second.val;
        second.val = temp;

        return head;
    }
}
