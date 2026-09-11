class Solution {
public:

    void toposortKahn(vector<vector<int>> &adj, int numCourses, vector<int> &res) {
        vector<int> indegree(numCourses, 0);
        for(auto it : adj) {
            for(auto u : it) {
                indegree[u]++;
            }
        }
        queue<int> q;
        for(int i =0; i<numCourses; i++) {
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()) {
            int n = q.front();
            res.push_back(n);
            q.pop();
            for(auto it : adj[n]) {
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites){
            int v = it[0];
            int u = it[1];
            adj[u].push_back(v);
        }
        vector<int> res;
        toposortKahn(adj, numCourses, res);
        return res.size() == numCourses ? res : vector<int>();
    }
};