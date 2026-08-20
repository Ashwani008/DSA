/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;

    void DFS(Node* old, Node* newNode) {

        for(auto n : old->neighbors) {

            if(mp.find(n) == mp.end()) {
                Node* newclone = new Node(n->val);
                mp[n] = newclone;

                newNode->neighbors.push_back(newclone);
                DFS(n, newclone);
            } else {
                newNode->neighbors.push_back(mp[n]);
            }
        }
        return;

    }

    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return node;
        mp.clear();
        Node* newNode = new Node(node->val);
        mp[node] = newNode;
        
        DFS(node, newNode);
        return newNode;
    }
};