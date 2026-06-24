/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* sptr = head;
        ListNode* fptr = head;
        if(head == NULL)
            return false;
        if (fptr->next == NULL)
            return false;
        fptr = fptr->next->next;
        while(fptr != NULL && fptr->next != NULL) {
            if (sptr == fptr)
                return true;
            sptr = sptr->next;
            fptr = fptr->next->next;
        }
        return false;
    }
};