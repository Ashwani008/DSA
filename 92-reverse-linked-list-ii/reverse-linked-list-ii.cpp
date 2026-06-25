/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* temp = head;
        if(temp == NULL || temp->next == NULL)
            return temp;
        
        ListNode* prev = NULL;
        // temp = temp->next;
        while(temp != NULL) {
            ListNode* nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head->next == NULL)
            return head;
        ListNode* temp=head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        temp = dummy;;
        for(int i =1; i<left;i++){
            temp = temp->next;
        }
        ListNode* prev = temp;
        ListNode* addtail = temp->next;

        temp = dummy;

        for(int i = 1; i<=right; i++) {
            temp = temp->next;
        }

        ListNode* remhead = temp->next;
        temp->next = NULL;
        ListNode* tempHead = reverse(addtail);
        prev->next = tempHead;
        addtail->next = remhead;

        return dummy->next;
        
    }
};