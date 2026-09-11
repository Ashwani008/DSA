class Solution {
public:
    void topoSortKahn(vector<int> adjl[], int numCourses, vector<int> &ans) {
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        for(int i =0; i < numCourses; i++) {

            for(auto it : adjl[i]) {
                indegree[it]++;
            }
        }
        for(int i =0; i<indegree.size(); i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int n = q.front();
            q.pop();
            ans.push_back(n);

            for(auto it : adjl[n]){
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        return;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adjl[numCourses];
        vector<int> ans;
        for(auto it : prerequisites) {
            int u = it[1];
            int v = it[0];
            adjl[u].push_back(v);
        }

        topoSortKahn(adjl, numCourses, ans);

        return ans.size() == numCourses ? true : false;
    
    }
};