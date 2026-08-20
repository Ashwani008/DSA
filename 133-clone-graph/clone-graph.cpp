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

    // void DFS(Node* old, Node* newNode) {

    //     for(auto n : old->neighbors) {

    //         if(mp.find(n) == mp.end()) {
    //             Node* newclone = new Node(n->val);
    //             mp[n] = newclone;

    //             newNode->neighbors.push_back(newclone);
    //             DFS(n, newclone);
    //         } else {
    //             newNode->neighbors.push_back(mp[n]);
    //         }
    //     }
    //     return;

    // }

    // Node* cloneGraph(Node* node) {
    //     if(node == NULL)
    //         return node;
    //     mp.clear();
    //     Node* newNode = new Node(node->val);
    //     mp[node] = newNode;
        
    //     DFS(node, newNode);
    //     return newNode;
    // }

    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return node;

        Node* newNode = new Node(node->val);
        mp[node] = newNode;

        queue<Node*> q;
        q.push(node);

        while(!q.empty()) {
            Node* n = q.front();
            Node* newclone = mp[n];
            q.pop();
            
            for(auto it : n->neighbors) {
                if(mp.find(it) == mp.end()) {
                    Node * cl = new Node(it->val);
                    mp[it] = cl;
                    q.push(it);
                    newclone->neighbors.push_back(cl);
                } else {
                    newclone->neighbors.push_back(mp[it]);
                }
            }

        }
        return newNode;
    }
};