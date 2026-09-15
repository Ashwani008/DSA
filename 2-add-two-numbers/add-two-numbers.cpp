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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* dummy = ans;
        int carry = 0;
        while(temp1 != NULL && temp2 != NULL) {
            int d = (temp1->val + temp2->val + carry);
            int v = d%10;
            carry = d/10;
            ListNode * node = new ListNode(v);
            ans->next = node;

            temp1 = temp1->next;
            temp2 = temp2->next;
            ans = node;
        }
        while(temp1 != NULL) {
            int d = (temp1->val + carry);
            int v = d%10;
            carry = d/10;
            ListNode* node = new ListNode(v);
            ans->next = node;
            ans = node;
            temp1 = temp1->next;
        }

        while(temp2 != NULL) {
            int d = (temp2->val + carry);
            int v = d%10;
            carry = d/10;
            ListNode* node = new ListNode(v);
            ans->next = node;
            ans = node;
            temp2 = temp2->next;
        }
        if(carry){
           ListNode* node = new ListNode(carry);
            ans->next = node; 
        }
        return dummy->next;
    }
};