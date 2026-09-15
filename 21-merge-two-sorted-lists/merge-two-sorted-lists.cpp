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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;

        ListNode *t1 = list1, *t2 = list2;
        ListNode* res = dummy;
        while(t1 != NULL && t2 != NULL){
            if(t1->val <= t2->val) {
                ListNode* nextptr = t1->next;
                res->next = t1;
                t1->next = t2;
                t1 = nextptr;
                res = res->next;
            } else {
                ListNode* nextptr = t2->next;
                res->next = t2;
                t2->next = t1;
                t2 = nextptr;
                res = res->next;
            }
            
        }

        if(t1 != NULL)
            res->next = t1;
        
        if(t2 != NULL)
            res->next = t2;
        
        return dummy->next;
    }
};