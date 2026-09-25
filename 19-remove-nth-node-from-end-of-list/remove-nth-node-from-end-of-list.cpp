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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* temp = dummy;
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        int pos = cnt - n;
        temp = dummy;
        for(int i =1; i<pos; i++){
            temp = temp->next;
        }
        ListNode* delNode = temp->next;
        if(delNode)
            temp->next = temp->next->next;
        else
            temp->next = NULL;
        
        delete delNode;
        return dummy->next;
    }
};