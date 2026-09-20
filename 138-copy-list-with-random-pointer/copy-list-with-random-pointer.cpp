/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> old_to_new;
        Node* curr = head;
        if(curr == NULL)
            return NULL;
        while(curr != NULL) {
            Node* node = new Node(curr->val);
            old_to_new[curr] = node;
            curr = curr->next;
        }

        curr = head;
        while(curr != NULL) {
            Node* newNode = old_to_new[curr];
            if(curr->next)
                newNode->next = old_to_new[curr->next];
            else
                newNode->next = NULL;
            
            if(curr->random)
                newNode->random = old_to_new[curr->random];
            else
                newNode->random = NULL;
            
            curr= curr->next;
        }
        return old_to_new[head];

    }
};