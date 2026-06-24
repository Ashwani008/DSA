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
        if (list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
        ListNode *res, *temphead=NULL;
        if (list1->val <= list2->val) {
            res= new ListNode(list1->val);
            list1 = list1->next;
        }
        else {
            res = new ListNode(list2->val);
            list2 = list2->next;
        }
        temphead = res;
        while(list1 != NULL && list2 != NULL) {
            if(list1->val < list2->val) {
                ListNode* temp = new ListNode(list1->val);
                res->next = temp;
                list1=list1->next;
                res = res->next;
            } else {
                ListNode* temp = new ListNode(list2->val);
                res->next = temp;
                list2=list2->next;
                res = res->next;
            }
        }
        if(list1 != NULL) {
            res->next = list1;
        }
        if(list2 != NULL) {
            res->next =list2;
        }
        return temphead;
    }
};