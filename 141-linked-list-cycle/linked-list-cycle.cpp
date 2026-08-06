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
    // bool hasCycle(ListNode *head) {
    //     map<ListNode*, int> mp;
    //     ListNode* temp = head;
    //     while(temp != NULL) {
    //         if(mp.find(temp) == mp.end())
    //             mp[temp] = 1;
    //         else
    //             return true;
    //         temp = temp->next;
    //     }
    //     return false;
    // }
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow)
                return true;
        }
        return false;
    }
};