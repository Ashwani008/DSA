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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode *prev = dummy;
        ListNode *curr = head;

        while(curr != NULL && curr->next != NULL) {
            ListNode* nextptr = curr->next->next;
            ListNode* second = curr->next;

            curr->next = nextptr;
            second->next = curr;
            prev->next = second;

            prev = curr;
            curr = nextptr;

        }
        return dummy->next;
    }
};